/*
 * bit_manipulation.c
 * Phase 1 - C Fundamentals for Embedded Systems
 *
 * In embedded systems, you control hardware by setting, clearing,
 * and toggling individual bits in registers. This is your most
 * used skill — master it first.
 *
 * How to run:
 *   gcc bit_manipulation.c -o bit_manipulation && ./bit_manipulation
 */

#include <stdio.h>
#include <stdint.h>   /* uint8_t, uint32_t — always use these in embedded */

/* Helper: print a byte as 8 bits */
void print_bits(const char *label, uint8_t value) {
    printf("%-30s = ", label);
    for (int i = 7; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
        if (i == 4) printf(" ");  /* space in middle for readability */
    }
    printf("  (0x%02X = %d)\n", value, value);
}

int main(void) {

    /* -------------------------------------------------------
     * 1. SET a bit  →  use OR  (|)
     *    To turn ON bit N:  value |= (1 << N)
     * ------------------------------------------------------- */
    printf("--- 1. SET A BIT ---\n");
    uint8_t reg = 0b00000000;
    print_bits("Start", reg);

    reg |= (1 << 3);   /* set bit 3 */
    print_bits("After SET bit 3", reg);

    reg |= (1 << 6);   /* set bit 6 */
    print_bits("After SET bit 6", reg);

    /* -------------------------------------------------------
     * 2. CLEAR a bit  →  use AND with NOT  (&~)
     *    To turn OFF bit N:  value &= ~(1 << N)
     * ------------------------------------------------------- */
    printf("\n--- 2. CLEAR A BIT ---\n");
    reg = 0b11111111;
    print_bits("Start", reg);

    reg &= ~(1 << 3);  /* clear bit 3 */
    print_bits("After CLEAR bit 3", reg);

    reg &= ~(1 << 7);  /* clear bit 7 */
    print_bits("After CLEAR bit 7", reg);

    /* -------------------------------------------------------
     * 3. TOGGLE a bit  →  use XOR  (^)
     *    To flip bit N:  value ^= (1 << N)
     * ------------------------------------------------------- */
    printf("\n--- 3. TOGGLE A BIT ---\n");
    reg = 0b10100000;
    print_bits("Start", reg);

    reg ^= (1 << 5);   /* toggle bit 5 — was 1, now 0 */
    print_bits("After TOGGLE bit 5", reg);

    reg ^= (1 << 5);   /* toggle again — back to 1 */
    print_bits("Toggle again bit 5", reg);

    /* -------------------------------------------------------
     * 4. CHECK a bit  →  use AND  (&)
     *    To read bit N:  (value >> N) & 1
     * ------------------------------------------------------- */
    printf("\n--- 4. CHECK A BIT ---\n");
    reg = 0b00101000;
    print_bits("Register", reg);

    uint8_t bit3 = (reg >> 3) & 1;
    uint8_t bit7 = (reg >> 7) & 1;
    printf("%-30s = %d\n", "Bit 3 is", bit3);
    printf("%-30s = %d\n", "Bit 7 is", bit7);

    /* -------------------------------------------------------
     * 5. REAL WORLD EXAMPLE
     *    Imagine 0x40 is a GPIO register for an LED on pin 2.
     *    Bit 2 = LED, Bit 5 = button input (read-only)
     * ------------------------------------------------------- */
    printf("\n--- 5. REAL WORLD: GPIO LED CONTROL ---\n");
    uint8_t GPIO_REG = 0b00100000;  /* bit 5 = button pressed */
    print_bits("Initial GPIO_REG", GPIO_REG);

    /* Turn LED ON (set bit 2) */
    GPIO_REG |= (1 << 2);
    print_bits("LED ON  (set bit 2)", GPIO_REG);

    /* Read button state (check bit 5) */
    uint8_t button = (GPIO_REG >> 5) & 1;
    printf("%-30s = %s\n", "Button state", button ? "PRESSED" : "NOT PRESSED");

    /* Turn LED OFF (clear bit 2) */
    GPIO_REG &= ~(1 << 2);
    print_bits("LED OFF (clear bit 2)", GPIO_REG);

    /* -------------------------------------------------------
     * YOUR EXERCISES — try these yourself:
     *
     * 1. Start with reg = 0b00001111
     *    Set bit 7, clear bit 0, then toggle bit 4
     *    What is the final value?
     *
     * 2. Write a function: uint8_t set_bit(uint8_t reg, uint8_t n);
     *    Write a function: uint8_t clear_bit(uint8_t reg, uint8_t n);
     *    Write a function: uint8_t toggle_bit(uint8_t reg, uint8_t n);
     *    Write a function: uint8_t check_bit(uint8_t reg, uint8_t n);
     *
     * 3. A register has 8 LEDs (bit 0 = LED0 ... bit 7 = LED7).
     *    Turn on only even LEDs (0, 2, 4, 6) using ONE line of code.
     *    Hint: what is 0b01010101 in hex?
     * ------------------------------------------------------- */

    printf("\nDone! Now attempt the 3 exercises above.\n");
    return 0;
}
