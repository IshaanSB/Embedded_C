/*
 * ATmega328P_UART.c
 * Configured for 16 MHz Clock, 9600 Baud Rate, 8 Data Bits, 1 Stop Bit, No Parity
 */

#define F_CPU 16000000UL // Define CPU frequency (16MHz is standard for Arduino Uno boards)
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

#include <avr/io.h>
#include <util/delay.h>

// Function Prototypes
void UART_init(unsigned int ubrr);
void UART_transmit(unsigned char data);
unsigned char UART_receive(void);
void UART_print(const char* str);

int main(void) {
    // 1. Initialize UART with the calculated Baud Rate Register Value
    UART_init(MYUBRR);
    
    // 2. Send a test string
    UART_print("UART Initialized. Type a character to echo:\r\n");

    // 3. Infinite loop to receive and echo back data
    while (1) {
        unsigned char received_char = UART_receive(); // Wait and read incoming character
        UART_transmit(received_char);                 // Echo the character back to the terminal
    }
    
    return 0;
}

// --- UART Functions ---

void UART_init(unsigned int ubrr) {
    // 1. Set Baud rate
    UBRR0H = (unsigned char)(ubrr >> 8); // Shift upper 8 bits into UBRR0H


  
    UBRR0L = (unsigned char)ubrr;        // Put lower 8 bits into UBRR0L
    
    // 2. Enable receiver and transmitter
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);
    
    // 3. Set frame format: 8 data bits, 1 stop bit, no parity
    // UCSZ01 and UCSZ00 set to 1 gives 8-bit data size
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void UART_transmit(unsigned char data) {
    // Wait for empty transmit buffer (UDRE0 flag in UCSR0A goes HIGH when empty)
    while (!(UCSR0A & (1 << UDRE0))) {
        // Do nothing until buffer is ready
    }
    
    // Put data into buffer, which physically sends the data
    UDR0 = data;
}

unsigned char UART_receive(void) {
    // Wait for data to be received (RXC0 flag in UCSR0A goes HIGH when unread data exists)
    while (!(UCSR0A & (1 << RXC0))) {
         // Do nothing until data arrives
    }
    
    // Get and return received data from the buffer
    return UDR0;
}



void UART_print(const char* str) {
    // Iterate through the string until the null-terminator is reached
    while (*str) {
        UART_transmit(*str++);
    }
}

uart communication protocol code, assignment or diy project: amke ur own uart protocol code to communicate between esp32, and arduino uno, try to display the recieved message on a lcd screen
