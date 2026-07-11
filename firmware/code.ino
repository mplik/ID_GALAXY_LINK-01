#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define BUTTON_PIN 2 // Upewnij się, że przylutowałeś do pinu D2

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

struct Star { int x, y; float speed; };
Star stars[20];

int stanProgramu = 0; // 0 = Gwiazdy, 1 = Powitanie
bool ostatniStanPrzycisku = HIGH;

void setup() {
  // Konfiguracja przycisku - INPUT_PULLUP jest kluczowe!
  pinMode(BUTTON_PIN, INPUT_PULLUP); 
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { for(;;); }
  
  for(int i = 0; i < 20; i++) {
    stars[i] = {random(0, 128), random(0, 64), random(1, 4) * 0.5f};
  }
}

void loop() {
  // Obsługa przycisku (wykrywanie kliknięcia)
  bool aktualnyStanPrzycisku = digitalRead(BUTTON_PIN);
  if (ostatniStanPrzycisku == HIGH && aktualnyStanPrzycisku == LOW) {
    stanProgramu = !stanProgramu; // Zmień tryb
    delay(50); // Prosty debouncing
  }
  ostatniStanPrzycisku = aktualnyStanPrzycisku;

  display.clearDisplay();

  if (stanProgramu == 0) {
    // TRYB 0: Animacja gwiazd (Twoja oryginalna)
    for(int i = 0; i < 20; i++) {
      display.drawPixel(stars[i].x, stars[i].y, WHITE);
      stars[i].x += stars[i].speed;
      if(stars[i].x > 128) { stars[i].x = 0; stars[i].y = random(0, 64); }
    }

    // 2. TEKST NA EKRANIE Z GWIAZDAMI (stałe dane)
    display.setTextSize(1);
    display.setTextColor(WHITE); // Color textu
    display.setCursor(10, 20); // Ustawienie kursora dla pierwszej lini
    display.println("RAFAL EMME");

    display.setCursor(10, 30); // Ustawienie kursora dla drugiej lini niżej
    display.println("36236 WAB");
  }
  else {
    // TRYB 1: Powitanie (Twoje nowe oryginalne)
    display.drawRect(0, 0, 128, 64, WHITE); // Ramka
    display.setTextSize(1);
    display.setCursor(5, 5);
    display.println("SYS: READY");
    
    display.setTextSize(2);
    display.setCursor(35, 30);
    display.println("RAFAL"); // Podmień na swoje imię
  }
  
  display.display();
  delay(30);
}