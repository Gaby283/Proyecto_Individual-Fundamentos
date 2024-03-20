// Declaración de arreglos y variables globales
int numBin[2]; // Arreglo para almacenar la representación binaria del número
int numGrey[2];      // Arreglo para almacenar la representación de código Gray
int comparacion;  // Variable para realizar la suma de bits binarios

void setup(void) {
  // Inicialización de comunicación serial
  Serial.begin(9600);
  // Configuración de pines como salidas digitales
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

// Función para convertir un número a su representación binaria
void Binario(int numero) {
  switch (numero) {
    // Casos para los números del 1 al 7
    case 1:
      numBin[0] = 0;
      numBin[1] = 0;
      numBin[2] = 1;
      break;
    case 2:
      numBin[0] = 0;
      numBin[1] = 1;
      numBin[2] = 0;
      break;
    case 3:
      numBin[0] = 0;
      numBin[1] = 1;
      numBin[2] = 1;
      break;
    case 4:
      numBin[0] = 1;
      numBin[1] = 0;
      numBin[2] = 0;
      break;
    case 5:
      numBin[0] = 1;
      numBin[1] = 0;
      numBin[2] = 1;
      break;
    case 6:
      numBin[0] = 1;
      numBin[1] = 1;
      numBin[2] = 0;
      break;
    case 7:
      numBin[0] = 1;
      numBin[1] = 1;
      numBin[2] = 1;
      break;
    // Caso por defecto para otros valores (0 o fuera de rango)
    default:
      numBin[0] = 0;
      numBin[1] = 0;
      numBin[2] = 0;
  }
}

// Función para escribir en los pines digitales según la representación de código Gray
void escribirCompuerta() {
  for (int i = 0; i < 3; i++) {
    if (numGrey[i] == 1) {
      digitalWrite(i + 8, HIGH); // Encender el pin correspondiente
    } else {
      digitalWrite(i + 8, LOW);  // Apagar el pin correspondiente
    }
  }
}

// Función para convertir la representación binaria a código Gray
void Grey() {
  numGrey[0] = numBin[0];
  numGrey[1] = sumaBinario(numBin[0], numBin[1]);
  numGrey[2] = sumaBinario(numBin[1], numBin[2]);
}

// Función para sumar dos bits binarios y obtener el resultado
int sumaBinario(int num1, int num2) {
  comparacion = 0;             // Reinicia la variable de comparación
  comparacion = num1 + num2;   // Realiza la suma de los bits
  if (comparacion == 1) {
    return comparacion;        // Si la suma es 1, retorna 1
  } else {
    return 0;                  // Si no, retorna 0
  }
}

void loop(void) {
  // Lectura del valor analógico del pin A5
  int reading = analogRead(A5);
  // Mapeo del valor analógico a un rango entre 0 y 7
  float mapeo = map(reading, 80, 600, 0, 7);
  // Redondeo del valor mapeado
  int redondeo = int(round(mapeo));
  // Conversión del número redondeado a su representación binaria
  Binario(redondeo);
  // Impresión del número redondeado por serial
  Serial.println(redondeo);
  Serial.println("binario");
  Serial.println(numBin[0]);  // Impresión del primer bit binario
  Serial.println(numBin[1]);  // Impresión del segundo bit binario
  Serial.println(numBin[2]);  // Impresión del tercer bit binario
  // Conversión de la representación binaria a código Gray
  Grey();
  Serial.println("grey");
  Serial.println(numGrey[0]);        // Impresión del A de código Gray
  Serial.println(numGrey[1]);        // Impresión del B de código Gray
  Serial.println(numGrey[2]);        // Impresión del C de código Gray que al final no influye 
  // Escritura en los pines digitales según la representación de código Gray
  escribirCompuerta();
  // Retardo de 1 segundo antes de repetir el bucle
  delay(1000);
}
