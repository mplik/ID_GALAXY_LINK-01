// ID_GALAXY_LINK — szablon kodu Arduino
// Umieść tutaj implementację projektu: animacje OLED, obsługa przycisku, zasilania

#include <Wire.h>
// #include <Adafruit_SSD1306.h> // odkomentuj i skonfiguruj według użytej biblioteki

// Przykładowe definicje pinów
const int BUTTON_PIN = 2; // pin przycisku (zewnętrzny pull-down/pull-up)

void setup() {
  // Inicjalizacja portów
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Inicjalizacja wyświetlacza i I2C
  Wire.begin();
  //ssd.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  // Wyświetl powitanie
  // display.clearDisplay();
  // display.setTextSize(2);
  // display.setTextColor(WHITE);
  // display.setCursor(0,10);
  // display.println("ID GALAXY");
  // display.display();
}

void loop() {
  // Odczyt przycisku
  bool pressed = digitalRead(BUTTON_PIN) == LOW; // dostosuj do schematu
  if (pressed) {
    // TODO: obsłuż przycisk — wyświetl powitanie lub zmień tryb
  }

  // TODO: animacja gwiazd na OLED

  delay(50);
}
