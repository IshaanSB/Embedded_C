#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


void create_solid_bmp_array(const char *filename, int width, int height, int make_white) {
    // 1. Calculate row sizes and padding constraints
    int row_data_size = width * 3; // 3 bytes per pixel (BGR)
    int padding_size = (4 - (row_data_size % 4)) % 4;
    int total_row_size = row_data_size + padding_size;
    
    uint32_t file_size = 54 + (total_row_size * height);
    uint32_t image_size = total_row_size * height;

    // 2. Create and zero-initialize a clean 54-byte header array
    uint8_t header[54] = {0};

    // --- BITMAP FILE HEADER (Bytes 0 to 13) ---
    header[0] = 0x42; // 'B'
    header[1] = 0x4D; // 'M'
    
    // Total File Size (Bytes 2-5 split into Little-Endian format)
    header[2] = (uint8_t)(file_size & 0xFF);
    header[3] = (uint8_t)((file_size >> 8) & 0xFF);
    header[4] = (uint8_t)((file_size >> 16) & 0xFF);
    header[5] = (uint8_t)((file_size >> 24) & 0xFF);

    // Pixel Offset (Bytes 10-13) -> Core data starts exactly at byte 54
    header[10] = 54;

    // --- DIB HEADER - BITMAPINFOHEADER (Bytes 14 to 53) ---
    // Info Header Size (Bytes 14-17) -> Always 40 bytes
    header[14] = 40;

    // Image Width (Bytes 18-21)
    header[18] = (uint8_t)(width & 0xFF);
    header[19] = (uint8_t)((width >> 8) & 0xFF);
    header[20] = (uint8_t)((width >> 16) & 0xFF);
    header[21] = (uint8_t)((width >> 24) & 0xFF);

    // Image Height (Bytes 22-25)
    header[22] = (uint8_t)(height & 0xFF);
    header[23] = (uint8_t)((height >> 8) & 0xFF);
    header[24] = (uint8_t)((height >> 16) & 0xFF);
    header[25] = (uint8_t)((height >> 24) & 0xFF);

    // Color Planes (Bytes 26-27) -> Must be 1
    header[26] = 1;

    // Bits Per Pixel (Bytes 28-29) -> 24-bit RGB
    header[28] = 24;

    // Raw Image Data Size (Bytes 34-37)
    header[34] = (uint8_t)(image_size & 0xFF);
    header[35] = (uint8_t)((image_size >> 8) & 0xFF);
    header[36] = (uint8_t)((image_size >> 16) & 0xFF);
    header[37] = (uint8_t)((image_size >> 24) & 0xFF);

    // Horizontal & Vertical Resolution (Bytes 38-45) -> 2835 ppm (~72 DPI)
    // 2835 in hex is 0x00000B13 -> Little endian: 13, 0B, 00, 00
    header[38] = 0x13; header[39] = 0x0B; 
    header[42] = 0x13; header[43] = 0x0B;

    // (Remaining bytes 46-53 represent colors used/important, safely left as 0)

    // 3. Write out to the file
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    // Write the entire constructed metadata array at once
    fwrite(header, sizeof(uint8_t), 54, file);

    // 4. Fill Pixel Canvas
    uint8_t color_byte = make_white ? 255 : 0; // 255 for White, 0 for Black
    uint8_t pixel[3] = {color_byte, color_byte, color_byte};
    uint8_t pixel1[3]={0, 0, 0};
    uint8_t padding[3] = {0, 0, 0};

    for (int y = 0; y < height; y++) {
        
        for (int x = 0; x < width; x++) {
	 if(x<width/4){
            fwrite(pixel1, sizeof(uint8_t), 3, file);
        }
	
	 else if(y<height/4){
            fwrite(pixel1, sizeof(uint8_t), 3, file);
        }
	
	 else if(y>(3*height)/4){
            fwrite(pixel1, sizeof(uint8_t), 3, file);
        }
	
	 else if(x>(3*width)/4){
            fwrite(pixel1, sizeof(uint8_t), 3, file);
        }
	
	else {
	 fwrite(pixel, sizeof(uint8_t), 3, file);
	}

        
       
       }
	
               
	        
        
	
        // Inject row padding if the width is not a multiple of 4 bytes
        if (padding_size > 0) {
            fwrite(padding, sizeof(uint8_t), padding_size, file);
        }
    }

    fclose(file);
    printf("Successfully created '%s' (%dx%d) using a byte array!\n", filename, width, height);
}

int main() {
    int width = 1920;
    int height = 1080;

    // Generate a Full HD black screen
//    create_solid_bmp_array("array_black.bmp", width, height, 0);

    // Generate a Full HD white screen
    create_solid_bmp_array("array_new.bmp", width, height, 1);

    return 0;
}
