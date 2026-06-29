#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void invert_bmp(const char *input_filename, const char *output_filename) {
    // 1. Open the source image in binary read mode
    FILE *infile = fopen(input_filename, "rb");
    if (!infile) {
        printf("Error: Could not open input file %s\n", input_filename);
        return;
    }

    // 2. Read the 54-byte BMP header
    uint8_t header[54];
    if (fread(header, sizeof(uint8_t), 54, infile) != 54) {
        printf("Error: Failed to read full BMP header.\n");
        fclose(infile);
        return;
    }

    // 3. Verify this is actually a valid BMP file
    if (header[0] != 0x42 || header[1] != 0x4D) { // Check for 'B' and 'M'
        printf("Error: Not a valid BMP file.\n");
        fclose(infile);
        return;
    }

    // 4. Extract pixel offset, width, and height from header array (Little-Endian)
    uint32_t pixel_offset = header[10] | (header[11] << 8) | (header[12] << 16) | (header[13] << 24);
    int32_t width        = header[18] | (header[19] << 8) | (header[20] << 16) | (header[21] << 24);
    int32_t height       = header[22] | (header[23] << 8) | (header[24] << 16) | (header[25] << 24);
    uint16_t bpp         = header[28] | (header[29] << 8);

    // This basic logic handles standard uncompressed 24-bit RGB/BGR images
    if (bpp != 24) {
        printf("Error: This script only supports 24-bit true-color BMP images (Found: %d-bit).\n", bpp);
        fclose(infile);        return;
    }

    // 5. Open the target destination file in binary write mode
    FILE *outfile = fopen(output_filename, "wb");
    if (!outfile) {
        printf("Error: Could not create output file %s\n", output_filename);
        fclose(infile);
        return;
    }

    // Write the exact same header to the output file
    fwrite(header, sizeof(uint8_t), 54, outfile);

    // If there is any extra metadata between the header and pixel data, preserve it
    if (pixel_offset > 54) {
        uint32_t extra_bytes_count = pixel_offset - 54;
        uint8_t *extra_bytes = (uint8_t *)malloc(extra_bytes_count);
        fread(extra_bytes, 1, extra_bytes_count, infile);
        fwrite(extra_bytes, 1, extra_bytes_count, outfile);
        free(extra_bytes);
    }

    // 6. Calculate sizing constraints for the pixel data processing
    int row_data_size = width * 3; 
    int padding_size = (4 - (row_data_size % 4)) % 4;

    // Allocate memory blocks to read a single row at a time
    uint8_t *pixel_row = (uint8_t *)malloc(row_data_size);
    uint8_t *padding = (uint8_t *)malloc(padding_size);

    // 7. Loop through the pixel array row by row
    for (int y = 0; y < abs(height); y++) {
        // Read raw color data for one row
        fread(pixel_row, sizeof(uint8_t), row_data_size, infile);

        // Invert every single color channel byte (B, G, and R fields)
        for (int i = 0; i < row_data_size; i++) {
            pixel_row[i] = 255 - pixel_row[i];
        }

        // Write the inverted row out to the new file
        fwrite(pixel_row, sizeof(uint8_t), row_data_size, outfile);

        // Read and write the padding bytes completely unmodified (they are just spacer zeros)
        if (padding_size > 0) {
            fread(padding, sizeof(uint8_t), padding_size, infile);
            fwrite(padding, sizeof(uint8_t), padding_size, outfile);
        }
    }

    // Clean up memory and close handlers
    free(pixel_row);
    free(padding);
    fclose(infile);
    fclose(outfile);

    printf("Success! Created negative image: '%s'\n", output_filename);
}

int main() {
    // Make sure your input image file matches this exact name and is in the same folder
    invert_bmp("sample_1920×1280.bmp", "lenna_negative.bmp");
    return 0;
}
