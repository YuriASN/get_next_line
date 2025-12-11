*This project has been created as part of the 42 curriculum by ysantos-*

## Description
This is a project of a function that will read from a file descriptor a single line (up to new line or end of file), each time it's called and return it in a allocated string.  

## Instructions
The program that uses the function will need a macro named BUFFER_SIZE, to set the size max that read() will use on it's buffer.  
It receives a parameter that's the File Descriptor to be read from, and return:  
	1. The first line, if it's the first call.  
	2. Next line from previous read.  
	3. NULL, if EOF has been reached before, or error occurs.  
The program is in charge to handle the open() and close() of FD, and free the string returned.  

## Resources
A [static variable](https://www.geeksforgeeks.org/c/static-variables-in-c/) was used to keep the data from last read() available for the next call.  
The [read()](https://man7.org/linux/man-pages/man2/read.2.html) function is the one who reads from file descriptor and store what was read on `buffer`.  
The [malloc()](https://man7.org/linux/man-pages/man3/free.3.html) function was used to allocate memory for the string that will be returned.  
The [free()](https://man7.org/linux/man-pages/man3/free.3.html) function was used to manage incomplete strings that needed to be added more later.  

## Algorithm
As the buffer size and string size can be any, the algorithm was done to run until `\n` or EOF is found to return what was read.  
It'll read from FD to `buffer`, copy `buffer` to `str` up to `\n` or EOF moving buffer pointer foward so what was copied is left behind.  
Then it'll see if there's already a `\n` in `buffer` to break the loop with `str` having everything that was read up to `\n` or EOF.  
On the call after EOF, read() will return 0 therefore `i` will be 0 breaking the loop while leaving `str` as NULL so caller knows that either file ended or error occured.