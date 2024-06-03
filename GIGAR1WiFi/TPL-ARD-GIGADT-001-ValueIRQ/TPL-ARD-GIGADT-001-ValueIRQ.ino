/**
 * Test Scenario ID : TPL-ARD-GIGADT-001-ValueIRQ
 *
 * This sketch obtains the border touch co-ordinates via interrupts
 *
 * Test Case IDs :
 * TPL-ARD-GIGADT-001-ValueIRQ-TL -> Get border x,y value for top left corner
 * TPL-ARD-GIGADT-001-ValueIRQ-TR -> Get border x,y value for top right corner
 * TPL-ARD-GIGADT-001-ValueIRQ-BR -> Get border x,y value for bottom right corner
 * TPL-ARD-GIGADT-001-ValueIRQ-BL -> Get border x,y value for bottom left corner
 *
 * Test Setup: Arduino GIGA R1 WiFi (ABX00063) with GIGA Display Touch Shield (ASX00039)
 *
 * Initial author: Ali Jahangiri @aliphys
 */

#include "Arduino_GigaDisplayTouch.h"

const char testScenarioID[] = "TPL-ARD-GIGADT-001-ValueIRQ";

Arduino_GigaDisplayTouch touchDetector;

bool isBorderObtained = false;

int samples = 20;

void gigaTouchHandler(uint8_t contacts, GDTpoint_t* points) {
  Serial.print("Contacts: ");
  Serial.println(contacts);

  if (contacts == 1) {
    /* First touch point */
    Serial.print(points[0].x);
    Serial.print(" ");
    Serial.println(points[0].y);
  }
}

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
    Serial.println("TPL-ARD-GIGADT-001-ValueIRQ-TL");
    Serial.println("Get border x,y value for top left corner...");

    int xa[5]; int ya[5];
    int ia= 0;
    isBorderObtained = false;
    while(!isBorderObtained) {
        
        uint8_t contacts;
        GDTpoint_t points[5];
        contacts = touchDetector.getTouchPoints(points);
        
        if (contacts == 1) {
            Serial.print("Point: ");
            Serial.print(points[0].x);
            xa[ia] = points[0].x;
            Serial.print(" ");
            Serial.println(points[0].y);
            ya[ia] = points[0].y;
            ia++;
        }

        if (ia == samples) {
            isBorderObtained = true;
            int xVal = 100;
            int yVal = 100;
            for (int j = 1; j < samples; j++) {
                xVal = max(xa[j],xVal);
                yVal = min(ya[j],yVal);
            }
            Serial.print("Top left border values are: ");
            Serial.print(xVal);
            Serial.print(", ");
            Serial.println(yVal);
        
        }

        delay(1);
    }

    delay(2000);

    Serial.println("---");
    Serial.print("Test Case ID: ");
    Serial.println("TPL-ARD-GIGADT-001-ValueIRQ-TR");
    Serial.println("Get border x,y value for top right corner...");

    int xb[5]; int yb[5];
    int ib= 0;
    isBorderObtained = false;
    while(!isBorderObtained) {
        
        uint8_t contacts;
        GDTpoint_t points[5];
        contacts = touchDetector.getTouchPoints(points);
        
        if (contacts == 1) {
            Serial.print("Point: ");
            Serial.print(points[0].x);
            xb[ib] = points[0].x;
            Serial.print(" ");
            Serial.println(points[0].y);
            yb[ib] = points[0].y;
            ib++;
        }

        if (ib == samples) {
            isBorderObtained = true;
            int xVal = 100;
            int yVal = 100;
            for (int j = 1; j < samples; j++) {
                xVal = max(xb[j],xVal);
                yVal = max(yb[j],yVal);
            }
            Serial.print("Top right border values are: ");
            Serial.print(xVal);
            Serial.print(", ");
            Serial.println(yVal);
        
        }

        delay(1);
    }

    delay(2000);

    Serial.println("---");
    Serial.print("Test Case ID: ");
    Serial.println("TPL-ARD-GIGADT-001-ValueIRQ-BR");
    Serial.println("Get border x,y value for bottom right corner...");

    int xc[5]; int yc[5];
    int ic= 0;
    isBorderObtained = false;
    while(!isBorderObtained) {
        
        uint8_t contacts;
        GDTpoint_t points[5];
        contacts = touchDetector.getTouchPoints(points);
        
        if (contacts == 1) {
            Serial.print("Point: ");
            Serial.print(points[0].x);
            xc[ic] = points[0].x;
            Serial.print(" ");
            Serial.println(points[0].y);
            yc[ic] = points[0].y;
            ic++;
        }

        if (ic == samples) {
            isBorderObtained = true;
            int xVal = 100;
            int yVal = 100;
            for (int j = 1; j < samples; j++) {
                xVal = min(xc[j],xVal);
                yVal = max(yc[j],yVal);
            }
            Serial.print("Bottom right border values are: ");
            Serial.print(xVal);
            Serial.print(", ");
            Serial.println(yVal);
        
        }

        delay(1);
    }

    delay(2000);

    Serial.println("---");
    Serial.print("Test Case ID: ");
    Serial.println("TPL-ARD-GIGADT-001-ValueIRQ-BL");
    Serial.println("Get border x,y value for bottom left corner...");

    int xd[5]; int yd[5];
    int id= 0;
    isBorderObtained = false;
    while(!isBorderObtained) {
        
        uint8_t contacts;
        GDTpoint_t points[5];
        contacts = touchDetector.getTouchPoints(points);
        
        if (contacts == 1) {
            Serial.print("Point: ");
            Serial.print(points[0].x);
            xd[id] = points[0].x;
            Serial.print(" ");
            Serial.println(points[0].y);
            yd[id] = points[0].y;
            id++;
        }

        if (id == samples) {
            isBorderObtained = true;
            int xVal = 100;
            int yVal = 100;
            for (int j = 1; j < samples; j++) {
                xVal = min(xd[j],xVal);
                yVal = min(yd[j],yVal);
            }
            Serial.print("Bottom left border values are: ");
            Serial.print(xVal);
            Serial.print(", ");
            Serial.println(yVal);
        
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