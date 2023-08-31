
# Photo Magic Project - FIbonaccy LFSR Image Encryption and Decryption

Welcome to the Photo Magic project! This project demonstartes the encryption and decryption of images using Fibonaccy Linear Feedback  Shift Register algorithm. The Fibonacci LFSR is a pseudorandom number generator that can be used for cryptographic purposes. In this project, we utilize it to transform an image into a scrambled form, making it appear as if it's "magically" encrypted.

Here are the result which I feed image in

![encrypted process](/encode.png)
![decrypted process](/decode.png)

To run the program, you need to have c++ 17 installed and SFML library install

Then, just type 

    > make

Auto command will compile easy file, then type

    > PhotoMagic <image file> <seed>

Then the program will generate and encode image in the same directory


