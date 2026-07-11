# ID_GALAXY_LINK — Dokumentacja projektu

## Przegląd
ID_GALAXY_LINK to interaktywny identyfikator personalny oparty na mikrokontrolerze Arduino Nano i wyświetlaczu OLED. Projekt służy jako futurystyczna wizytówka na targi i eventy.

## Zawartość repozytorium
- `README.md` — opis projektu.
- `ID_GALAXY.html` — strona produktu (frontend).
- `ID_GALAXY.css` — style strony.
- `assets/ID_GALAXY_preview.svg` — obraz projektu / podgląd.
- `firmware/code.ino` — szablon kodu Arduino.

## Hardware (skrót)
- Arduino Nano (ATmega328P)
- OLED 0.96" I2C
- Moduł ładowania TP4056 (USB-C)
- Przycisk funkcyjny
- Akumulator Li-Po 3.7V (zgodny z TP4056)

## Wiring (przykład)
- OLED VCC → 3.3V/5V (zgodnie z modułem)
- OLED GND → GND
- OLED SDA → A4 (Arduino Nano)
- OLED SCL → A5 (Arduino Nano)
- Przycisk → pin D2 (przycisk do GND z pullup)
- TP4056 OUT+ → V+ akumulatora, OUT- → GND

## Software — jak uruchomić
1. Otwórz `firmware/code.ino` w Arduino IDE lub PlatformIO.
2. Zainstaluj bibliotekę SSD1306 (Adafruit lub U8g2) oraz Wire.
3. Wgraj na Arduino Nano.

## Development TODO
- [ ] Zaimplementować animację gwiazd na wyświetlaczu OLED
- [ ] Dodać obsługę trybów przycisku
- [ ] Dodać instrukcję montażu mechanicznego i BOM

## Licencja
Projekt domyślnie open-source. Dodaj plik `LICENSE` jeśli chcesz określić konkretną licencję.
