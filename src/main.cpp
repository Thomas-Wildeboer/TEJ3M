#define PORT 80 // TCP port to listen to

// Include necessary libraries
#include "Arduino.h"
#include <ESP8266WiFi.h>

// WiFi SSID and password
const char* SSID = "ssid";
const char* PASS = "password";

// Server instance
WiFiServer server(PORT);

// Right motor control pins (DRV8833)
int Right1 = 15;
int Right2 = 16;

// Left motor control pins (DRV8833)
int Left1 = 13;
int Left2 = 14;

// Declare motor control functions
void motors_stop();
void motors_forward();
void motors_right();
void motors_left();
void motors_backward();

void setup() {
    // Set motor pins as outputs
    pinMode(Right1, OUTPUT);
    pinMode(Right2, OUTPUT);
    pinMode(Left1, OUTPUT); 
    pinMode(Left2, OUTPUT);
    
    // Create WiFi connection
    WiFi.begin(SSID, PASS);

    // Start server
    server.begin();
}
 
void loop() {
    // Handle HTTP requests
    WiFiClient client = server.available();

    // Return if client is null
    if (!client) {
        return;
    }

    // Wait for client request
    while(!client.available()){
        delay(1);
    }

    // Get HTTP request url
    String req = client.readStringUntil('\r');

    // HTTP responses
    if (req.indexOf("/stop") != -1) {
        motors_stop();
    }
    else if (req.indexOf("/forward") != -1) {
        // Run motors until client sends another request
        while(true){
            motors_forward();
            if(client.available()){
                break;
            }
        }
    }
    else if (req.indexOf("/left") != -1) {
        while(true){
            motors_left();
            if(client.available()){
                break;
            }
        }
    }
    else if (req.indexOf("/right") != -1) {
        while(true){
            motors_right();
            if(client.available()){
                break;
            }
        }
    }
    else if (req.indexOf("/backward") != -1) {
        while(true){
            motors_backward();
            if(client.available()){
                break;
            }
        }
    }
}

// Motor control functions
void motors_stop() {
    digitalWrite(Right1, LOW);
    digitalWrite(Right2, LOW);
    digitalWrite(Left1, LOW);
    digitalWrite(Left2, LOW);
}

void motors_forward() {
    digitalWrite(Right1, HIGH);
    digitalWrite(Right2, LOW);
    digitalWrite(Left1, HIGH);
    digitalWrite(Left2, LOW);
}

void motors_right() {
    digitalWrite(Right1, LOW);
    digitalWrite(Right2, HIGH);
    digitalWrite(Left1, LOW);
    digitalWrite(Left2, LOW);
}

void motors_left() {
    digitalWrite(Right1, LOW);
    digitalWrite(Right2, LOW);
    digitalWrite(Left1, LOW);
    digitalWrite(Left2, HIGH);
}

void motors_backward() {
    digitalWrite(Right1, LOW);
    digitalWrite(Right2, HIGH);
    digitalWrite(Left1, LOW);
    digitalWrite(Left2, HIGH);
}