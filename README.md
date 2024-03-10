

## Summary of CODE:

### setup():
- Initializes serial communication at a baud rate of 9600.
- Connects to the specified WiFi network using provided SSID and password.
- Initializes the 16x2 LCD display and turns on the backlight.

### loop():
- Creates an HTTPClient instance to make HTTP requests.
- Sends an HTTP GET request to a specified endpoint with an API key.
- Parses the JSON response and retrieves values for "line_1" and "line_2".
- Clears the LCD display and prints the retrieved values on lines 1 and 2.
- Delays for 1 second before repeating the loop.

## Purpose:
This Arduino code is written to demonstrate a simple IoT application where a microcontroller device connects to a WiFi network, fetches data from a remote server via HTTP requests, and displays the retrieved data on an LCD screen. 
It can be used as a basis for various projects involving real-time data monitoring or display.

## Riddle:
I speak without a mouth and hear without ears. I have no body, but I come alive with wind. What am I?

Extra: Why do orphans suck at web design?
