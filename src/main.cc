#include <Arduino.h>
#include <BleKeyboard.h>

const uint8_t PIN_BUTTON = 15;
BleKeyboard bleKeyboard;

void
setup()
{
  bleKeyboard = BleKeyboard("Task killer");

  // Begin serial for debug log
  Serial.begin(115200);

  // Start Bluetooth
  bleKeyboard.begin();

  // Button
  if (!digitalPinIsValid(PIN_BUTTON))
  {
    Serial.println("Invalid button pin");
    return;
  }

  pinMode(PIN_BUTTON, INPUT_PULLDOWN);
}

void
loop()
{
  if (bleKeyboard.isConnected() && digitalRead(PIN_BUTTON))
  {
    // Send keys
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press('c');
    bleKeyboard.releaseAll();
    delay(100);
  }
}
