/* Ground control station Demo
 *  by Kristopher Ellis
 *  for Idea Lab Kids
 *  
 *  Mabast and Khadim helped a litlle I guess
 *  
 *  
 *  
 * 
 */
 #include <RH_ASK.h>
// Include dependant SPI Library
#include <SPI.h>
String xaxis;
String yaxis;
//int yaxis = 100;
String str_xaxis;
String str_yaxis;
String str_out;
//float xaxis;
RH_ASK rf_driver;


void setup() {
  rf_driver.init();
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
   pinMode(6, OUTPUT);
  Serial.begin(9600);
  Serial.print("Hi");
}

void loop() {
  // Set buffer to size of expected message

  uint8_t buf[7];
  uint8_t buflen = sizeof(buf);
  //Serial.println(str_out);
  // Check if received packet is correct size
  if (rf_driver.recv(buf, &buflen))
  {

    // Message received with valid checksum
    // Get values from string

    // Convert received data into string
    str_out = String((char*)buf);

    // Split string into two values
    for (int i = 0; i < str_out.length(); i++) {
      if (str_out.substring(i, i + 1) == ",") {
        str_xaxis = str_out.substring(0, i);
        str_yaxis = str_out.substring(i + 1);
        break;
      }
    }

    // Print values to Serial Monitor
    Serial.print("X Axis: ");
    Serial.print(str_xaxis);
    Serial.print("   Y Axis: ");
    Serial.println(str_yaxis);
    //delay(33);
    //xaxis = str_xaxis
    // int xaxis = str_xaxis;
    //float str_xaxis;

    int xaxis = str_xaxis.toInt();// converts string to integer
    int yaxis = str_yaxis.toInt();
    //float xaxis;
    //Serial.print(xaxis);
    if (xaxis < 560 && xaxis > 540)
      //stop
    {
      digitalWrite(A2, HIGH);
      digitalWrite(A1, LOW);
      digitalWrite(A0, LOW);
      digitalWrite(A3, LOW);
      digitalWrite(A4, LOW);

      Serial.println("1");

    }
    else if (xaxis < 580 && xaxis > 560) //stop
    {
      digitalWrite(A1, HIGH);
      digitalWrite(A0, LOW);
      digitalWrite(A2, LOW);
      digitalWrite(A3, LOW);
      digitalWrite(A4, LOW);
      Serial.println("2");

    }
    else if (xaxis < 600 && xaxis > 580) //stop
    {
      digitalWrite(A2, LOW);
      digitalWrite(A1, LOW);
      digitalWrite(A2, LOW);
      digitalWrite(A0, HIGH);
      digitalWrite(A4, LOW);
      Serial.println("3");
    }
    else if (xaxis < 540 && xaxis > 520) //stop
    {
      digitalWrite(A1, LOW);
      digitalWrite(A0, LOW);
      digitalWrite(A2, LOW);
      digitalWrite(A3, HIGH);
      digitalWrite(A4, LOW);
      Serial.println("4");
    }
    else if (xaxis < 520 && xaxis > 500) //stop
    {
      digitalWrite(A1, LOW);
      digitalWrite(A0, LOW);
      digitalWrite(A2, LOW);
      digitalWrite(A3, LOW);
      digitalWrite(A4, HIGH);
      Serial.println("5");
    }
    else
    {
      //digitalWrite(A1, HIGH);
      //digitalWrite(A0, HIGH);
      //digitalWrite(A2, HIGH);
     // digitalWrite(A3, HIGH);
     //  digitalWrite(A4, HIGH);
      //  Serial.println("6");

    }

  }
  int yaxis = str_yaxis.toInt();
  if (yaxis < 560 && yaxis > 540)
    //stop
  {
    digitalWrite(6, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    //  Serial.println("11");

  }
  else if (yaxis < 580 && yaxis > 560)
    //stop
  {
    digitalWrite(6, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
    //  Serial.println("11");

  }
  else if (yaxis < 600 && yaxis > 580) //stop
  {
    digitalWrite(6, LOW);
    digitalWrite(4, LOW);
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);;
    //  Serial.println("10");

  }
  else if (yaxis < 540 && yaxis > 520) //stop
  {
    digitalWrite(6, LOW);
    digitalWrite(2, LOW);
    digitalWrite(5, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    // Serial.println("9");
  }


  else if (yaxis < 520 && yaxis > 500) //stop
  {
    digitalWrite(6, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    //Serial.println("8");
  }
  else
  {
    //digitalWrite(6, HIGH);
    //digitalWrite(4, HIGH);
    //digitalWrite(5, HIGH);
    //digitalWrite(3, HIGH);
   // digitalWrite(2, HIGH);
    //  Serial.println("7");

  }

}
