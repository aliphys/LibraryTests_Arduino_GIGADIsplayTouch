/**
 * Test Scenario ID : TPL-ARD-GIGADT-001-PointsPolling
 *
 * This sketch checks that correct number of touch points are detected by the touch controller.
 *
 * Test Case IDs :
 * TPL-ARD-GIGADT-001-PointsPolling-1 -> Touch screen with one finger
 * TPL-ARD-GIGADT-001-PointsPolling-2 -> Touch screen with two fingers
 * TPL-ARD-GIGADT-001-PointsPolling-3 -> Touch screen with three fingers
 * TPL-ARD-GIGADT-001-PointsPolling-4 -> Touch screen with four fingers
 * TPL-ARD-GIGADT-001-PointsPolling-5 -> Touch screen with five fingers
 * TPL-ARD-GIGADT-001-PointsPolling-6 -> Touch screen with six fingers
 *
 * Test Setup: Arduino GIGA R1 WiFi (ABX00063) with GIGA Display Touch Shield (ASX00039)
 *
 * Initial author: Ali Jahangiri @aliphys
 */

#include "Arduino_GigaDisplayTouch.h"

const char testScenarioID[] = "TPL-ARD-GIGADT-001-ValuePolling";

Arduino_GigaDisplayTouch touchDetector;

bool isTouchDetected = false;

void setup() {
    Serial.begin(115200);
    while (!Serial){}

    Serial.println();
    Serial.println("---------");
    Serial.print("Test Scenario ID: ");
    Serial.println(testScenarioID);
    Serial.println("---------");
    Serial.println();

    if (touchDetector.begin()) {
        Serial.print("Touch controller init - OK");
    }
    else {
        Serial.print("Touch controller init - FAILED");
        while (1);
    }

    Serial.println("---");
    Serial.print("Test Case ID: ");
    Serial.println("TPL-ARD-GIGADT-001-PointsPolling-1");
    Serial.println("Touch screen with one finger...");

    isTouchDetected = false;
    while(!isTouchDetected) {
        
        uint8_t contacts;
        GDTpoint_t points[5];
        contacts = touchDetector.getTouchPoints(points);

        
        if (contacts == 1) {
            Serial.print("Single Touch Detected!: ");
            Serial.print(points[0].x);
            Serial.print(" ");
            Serial.println(points[0].y);
            isTouchDetected = true;
        }

        delay(1);
    }

    delay(2000);

    Serial.println("---");
    Serial.print("Test Case ID: ");
    Serial.println("TPL-ARD-GIGADT-001-PointsPolling-2");
    Serial.println("Touch screen with two fingers...");

    isTouchDetected = false;
    while(!isTouchDetected) {
        
        uint8_t contacts;
        GDTpoint_t points[5];
        contacts = touchDetector.getTouchPoints(points);

        
        if (contacts == 2) {
            Serial.print("Two Fingers Detected!: ");
            Serial.print(points[0].x);
            Serial.print(" ");
            Serial.println(points[0].y);
            isTouchDetected = true;
        }

        delay(1);
    }

    delay(2000);

    Serial.println("---");
    Serial.print("Test Case ID: ");
    Serial.println("TPL-ARD-GIGADT-001-PointsPolling-3");
    Serial.println("Touch screen with three fingers...");

    isTouchDetected = false;
    while(!isTouchDetected) {
        
        uint8_t contacts;
        GDTpoint_t points[5];
        contacts = touchDetector.getTouchPoints(points);

        
        if (contacts == 3) {
            Serial.print("Three Fingers Detected!: ");
            Serial.print(points[0].x);
            Serial.print(" ");
            Serial.println(points[0].y);
            isTouchDetected = true;
        }

        delay(1);
    }

    delay(2000);

    Serial.println("---");
    Serial.print("Test Case ID: ");
    Serial.println("TPL-ARD-GIGADT-001-PointsPolling-4");
    Serial.println("Touch screen with four fingers...");

    isTouchDetected = false;
    while(!isTouchDetected) {
        
        uint8_t contacts;
        GDTpoint_t points[5];
        contacts = touchDetector.getTouchPoints(points);

        
        if (contacts == 4) {
            Serial.print("Four Fingers Detected!: ");
            Serial.print(points[0].x);
            Serial.print(" ");
            Serial.println(points[0].y);
            isTouchDetected = true;
        }

        delay(1);
    }

    delay(2000);

    Serial.println("---");
    Serial.print("Test Case ID: ");
    Serial.println("TPL-ARD-GIGADT-001-PointsPolling-5");
    Serial.println("Touch screen with five fingers...");

    isTouchDetected = false;
    while(!isTouchDetected) {
        
        uint8_t contacts;
        GDTpoint_t points[5];
        contacts = touchDetector.getTouchPoints(points);

        
        if (contacts == 5) {
            Serial.print("Five Fingers Detected!: ");
            Serial.print(points[0].x);
            Serial.print(" ");
            Serial.println(points[0].y);
            isTouchDetected = true;
        }

        delay(1);
    }

    delay(2000);

    Serial.println();
    Serial.println("---------");
    Serial.print("End of Test Scenario ID: ");
    Serial.println(testScenarioID);
    Serial.println("---------");
    Serial.println();
    
}

void loop() {
        
}