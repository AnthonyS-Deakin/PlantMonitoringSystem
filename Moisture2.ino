#include <SD.h> // Include the SD library

// Define the chip select pin for your SD card module
const int chipSelect = 10; // Change this to the appropriate pin for your setup

void setup() {
  Serial.begin(9600);
  // Initialize the SD card with the chip select pin
  if (!SD.begin(chipSelect)) {
    Serial.println("SD card initialization failed!");
    return;
  }
  Serial.println("SD card initialized.");
}

void loop() {
  int val;
  val = analogRead(A0); // Connect sensor to Analog 0

  // Create a CSV-formatted string containing the data
  String dataString = String(val) + "," + String(millis()) + "\n";

  // Open the file in append mode (FILE_WRITE) and write the data to it
  File dataFile = SD.open("data.csv", FILE_WRITE);
  if (dataFile) {
    dataFile.print(dataString);
    dataFile.close();
    Serial.println("Data saved to data.csv");
  } else {
    Serial.println("Error opening data.csv");
  }

  // Print the value to the serial port
  Serial.println(val);

  delay(1000);
}
