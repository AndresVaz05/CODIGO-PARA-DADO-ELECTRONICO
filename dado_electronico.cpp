/*
  🎲 Dado Electrónico con Arduino
  Proyecto académico para la materia Electrónica Básica.
  Genera un número aleatorio del 1 al 6 al presionar un pulsador,
  y lo muestra mediante 7 LEDs en forma de dado.
  
  Autor: Juan Carlos Silva Licea - Efraín Andrés Vázquez Ramos
  Docente: Ing. Daniel Eduardo Cruz Morales
  Fecha: 2025
*/

// ============================================================
// 1. DEFINICIÓN DE PINES
// ============================================================

// Pines para los LEDs (D2 al D8)
const int LED1 = 2;   // Esquina superior izquierda
const int LED2 = 3;   // Esquina superior derecha
const int LED3 = 4;   // Centro izquierdo
const int LED4 = 5;   // Centro (punto central)
const int LED5 = 6;   // Centro derecho
const int LED6 = 7;   // Esquina inferior izquierda
const int LED7 = 8;   // Esquina inferior derecha

// Pin para el pulsador (D9)
const int PUSH = 9;

// Variable para almacenar el número generado (1-6)
int RESULTADO = 0;

// ============================================================
// 2. FUNCIÓN setup() – Se ejecuta una vez al inicio
// ============================================================
void setup()
{
  // Configurar todos los pines de LEDs como salidas
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  
  // Configurar el pin del pulsador como entrada con resistencia pull-up interna
  // NOTA: Con INPUT_PULLUP, el pin lee HIGH cuando NO está presionado,
  // y LOW cuando se presiona (lógica inversa a la del PDF).
  pinMode(PUSH, INPUT_PULLUP);
  
  // Iniciar la comunicación serial para depuración
  Serial.begin(9600);
  
  // Semilla para números aleatorios (basada en una lectura analógica)
  randomSeed(analogRead(A0));
}

// ============================================================
// 3. FUNCIÓN loop() – Se ejecuta continuamente
// ============================================================
void loop()
{
  // Leer el estado del pulsador
  // Con INPUT_PULLUP: LOW = presionado, HIGH = no presionado
  if (digitalRead(PUSH) == LOW)
  {
    // Generar un número aleatorio entre 1 y 6
    RESULTADO = random(1, 7);
    
    // Enviar el valor por el monitor serial (para depuración)
    Serial.println(RESULTADO);
    
    // Retardo para evitar rebotes (debounce) y múltiples lecturas
    delay(500);
  }
  
  // ============================================================
  // 4. MOSTRAR EL NÚMERO EN LOS LEDs
  // ============================================================
  
  // Número 1 – solo el LED central (LED4)
  if (RESULTADO == 1)
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, HIGH);  // Centro encendido
    digitalWrite(LED5, LOW);
    digitalWrite(LED6, LOW);
    digitalWrite(LED7, LOW);
  }
  
  // Número 2 – esquinas opuestas (LED1 y LED7)
  if (RESULTADO == 2)
  {
    digitalWrite(LED1, HIGH);  // Esquina superior izquierda
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);   // Centro apagado
    digitalWrite(LED5, LOW);
    digitalWrite(LED6, LOW);
    digitalWrite(LED7, HIGH);  // Esquina inferior derecha
  }
  
  // Número 3 – diagonal (LED3, LED4, LED5)
  if (RESULTADO == 3)
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);  // Centro izquierdo
    digitalWrite(LED4, HIGH);  // Centro
    digitalWrite(LED5, HIGH);  // Centro derecho
    digitalWrite(LED6, LOW);
    digitalWrite(LED7, LOW);
  }
  
  // Número 4 – cuatro esquinas (LED1, LED3, LED5, LED7)
  if (RESULTADO == 4)
  {
    digitalWrite(LED1, HIGH);  // Esquina superior izquierda
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);  // Centro izquierdo
    digitalWrite(LED4, LOW);   // Centro apagado
    digitalWrite(LED5, HIGH);  // Centro derecho
    digitalWrite(LED6, LOW);
    digitalWrite(LED7, HIGH);  // Esquina inferior derecha
  }
  
  // Número 5 – cuatro esquinas + centro (LED1, LED3, LED4, LED5, LED7)
  if (RESULTADO == 5)
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);  // Centro encendido
    digitalWrite(LED5, HIGH);
    digitalWrite(LED6, LOW);
    digitalWrite(LED7, HIGH);
  }
  
  // Número 6 – todas las posiciones EXCEPTO el centro (LED1, LED2, LED3, LED5, LED6, LED7)
  if (RESULTADO == 6)
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);  // Esquina superior derecha
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);   // Centro apagado
    digitalWrite(LED5, HIGH);
    digitalWrite(LED6, HIGH);  // Esquina inferior izquierda
    digitalWrite(LED7, HIGH);
  }
}