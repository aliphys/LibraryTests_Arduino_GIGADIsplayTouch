/**
 * Test Scenario ID : TPL-ARD-GIGADT-001-PointsIRQ
 *
 * This sketch checks that correct number of touch points are detected by the touch controller.
 *
 * Test Case IDs :
 * TPL-ARD-GIGADT-001-PointsIRQ-1 -> Touch screen with one finger
 * TPL-ARD-GIGADT-001-PointsIRQ-2 -> Touch screen with two fingers
 * TPL-ARD-GIGADT-001-PointsIRQ-3 -> Touch screen with three fingers
 * TPL-ARD-GIGADT-001-PointsIRQ-4 -> Touch screen with four fingers
 * TPL-ARD-GIGADT-001-PointsORQ-5 -> Touch screen with five fingers
 *
 * Test Setup: Arduino GIGA R1 WiFi (ABX00063) with GIGA Display Touch Shield (ASX00039)
 *
 * Initial author: Ali Jahangiri @aliphys
 */

#include "Arduino_GigaDisplayTouch.h"

const char testScenarioID[] = "TPL-ARD-GIGADT-001-ValueIRQ";

Arduino_GigaDisplayTouch touchDetector;
volatile bool oneTouchDetected = false;
volatile bool twoTouchDetected = false;
volatile bool threeTouchDetected = false;
volatile bool fourTouchDetected = false;
volatile bool fiveTouchDetected = false;


void gigaTouchHandler1(uint8_t contacts, GDTpoint_t* points) {
  if (contacts == 1) {
    Serial.print("Contacts: ");
    Serial.println(contacts);
    Serial.print(points[0].x);
    Serial.print(" ");
    Serial.println(points[0].y);
    delay(10);
    oneTouchDetected = true;
  }
}

void gigaTouchHandler2(uint8_t contacts, GDTpoint_t* points) {
  if (contacts == 2) {
    Serial.print("Contacts: ");
    Serial.println(contacts);
    Serial.print(points[0].x);
    Serial.print(" ");
    Serial.println(points[0].y);
    delay(10);
    twoTouchDetected = true;
  }
}

void gigaTouchHandler3(uint8_t contacts, GDTpoint_t* points) {
  if (contacts == 3) {
    Serial.print("Contacts: ");
    Serial.println(contacts);
    Serial.print(points[0].x);
    Serial.print(" ");
    Serial.println(points[0].y);
    delay(10);
    threeTouchDetected = true;
  }
}

void gigaTouchHandler4(uint8_t contacts, GDTpoint_t* points) {
  if (contacts == 4) {
    Serial.print("Contacts: ");
    Serial.println(contacts);
    Serial.print(points[0].x);
    Serial.print(" ");
    Serial.println(points[0].y);
    delay(10);
    fourTouchDetected = true;
  }
}

void gigaTouchHandler5(uint8_t contacts, GDTpoint_t* points) {
  if (contacts == 5) {
    Serial.print("Contacts: ");
    Serial.println(contacts);
    Serial.print(points[0].x);
    Serial.print(" ");
    Serial.println(points[0].y);
    delay(10);
    fiveTouchDetected = true;
  }
}

void setup() {
  Serial.begin(115200);
  while(!Serial) {}

  Serial.println();
  Serial.println("---------");
  Serial.print("Test Scenario ID: ");
  Serial.println(testScenarioID);
  Serial.println("---------");
  Serial.println();


  if (touchDetector.begin()) {
    Serial.println("Touch controller init - OK");
  } else {
    Serial.println("Touch controller init - FAILED");
    while(1) ;
  }

  Serial.println("---");
  Serial.print("Test Case ID: ");
  Serial.println("TPL-ARD-GIGADT-001-PointsIRQ-1");
  Serial.println("Touch screen with one finger...");

  touchDetector.onDetect(gigaTouchHandler1);
  delay(10);
  while (!oneTouchDetected) {};
  Serial.println("One Finger Detected!");
  delay(10);

  Serial.println("---");
  Serial.print("Test Case ID: ");
  Serial.println("TPL-ARD-GIGADT-001-PointsIRQ-2");
  Serial.println("Touch screen with two fingers...");

  touchDetector.onDetect(gigaTouchHandler2);
  delay(10);
  while (!twoTouchDetected) {};
  Serial.println("Two Fingers Detected!");
  delay(10);

  Serial.println("---");
  Serial.print("Test Case ID: ");
  Serial.println("TPL-ARD-GIGADT-001-PointsIRQ-3");
  Serial.println("Touch screen with three fingers...");

  touchDetector.onDetect(gigaTouchHandler3);
  delay(10);
  while (!threeTouchDetected) {};
  Serial.println("Three Fingers Detected!");
  delay(10);

  Serial.println("---");
  Serial.print("Test Case ID: ");
  Serial.println("TPL-ARD-GIGADT-001-PointsIRQ-4");
  Serial.println("Touch screen with four fingers...");

  touchDetector.onDetect(gigaTouchHandler4);
  delay(10);
  while (!fourTouchDetected) {};
  Serial.println("Four Fingers Detected!");
  delay(10);

  Serial.println("---");
  Serial.print("Test Case ID: ");
  Serial.println("TPL-ARD-GIGADT-001-PointsIRQ-5");
  Serial.println("Touch screen with five fingers...");

  touchDetector.onDetect(gigaTouchHandler5);
  delay(10);
  while (!fiveTouchDetected) {};
  Serial.println("Five Fingers Detected!");
  delay(10);

  Serial.println();
  Serial.println("---------");
  Serial.print("End of Test Scenario ID: ");
  Serial.println(testScenarioID);
  Serial.println("---------");
  Serial.println();

}

void loop() {

}
