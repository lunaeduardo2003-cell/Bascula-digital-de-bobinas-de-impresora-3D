# Bascula-digital-de-bobinas-de-impresora-3D
Este proyecto consiste en una báscula digital diseñada para medir el peso de bobinas de filamento para impresoras 3D. El objetivo es facilitar a los usuarios de impresoras 3D conocer el peso exacto de sus bobinas y, por ende, el filamento disponible, evitando interrupciones inesperadas durante la impresión.

Problema que resuelve:
- Dificultad para medir de manera precisa la cantidad de filamento restante en bobinas.
- Evita desperdicio de filamento y errores por falta de material durante impresiones largas.

Propósito y alcance:
- Medir peso de bobinas de filamento estándar para impresoras 3D.
- Mostrar resultados en una pantalla LCD.
- Alertar cuando el peso es menor a un límite establecido.
- Simulación realizada en Tinkercad (física y electrónica virtual).
  
# Requesitos e instalacion
Requisitos
- Arduino IDE
- Librería LiquidCrystal.h
- Hardware o simulación en Tinkercad:
- Arduino UNO
- Pantalla LCD 16x2
- Sensor FSR (celda de carga)
- LED de alerta
# Instalacion
- Clonar el repositorio:
git clone https://github.com/usuario/bascula-digital.git
- Abrir main.ino en Arduino IDE.
- Instalar la librería LiquidCrystal si no está instalada.

# Cómo usarlo
- Ejecutar en Arduino IDE
- Conectar el Arduino o usar la simulación en Tinkercad.
- Subir el código main.ino.
- Colocar la bobina sobre el sensor.
- Observar el peso en la pantalla LCD.
- Si el peso está por debajo del límite, se encenderá el LED de alerta.

Comandos importantes (si quieres usar Git):
git add .
git commit -m "Agregar proyecto báscula digital"
git push -u origin main


# Cómo funciona internamente
Arquitectura general:
El sistema está compuesto por los siguientes módulos:
- Sensor de peso (FSR / celda de carga virtual en Tinkercad): Detecta la fuerza/peso de la bobina.
- Microcontrolador (Arduino UNO): Procesa la señal del sensor, calcula el peso y controla el sistema.
- Pantalla LCD: Muestra el peso calculado en tiempo real.
- LED de alerta: Se enciende si el peso cae por debajo de un umbral.

Flujo de funcionamiento:
- La bobina se coloca sobre la báscula.
- El sensor detecta la fuerza aplicada.
- Arduino convierte la señal analógica del sensor a un valor de peso.
- El peso se muestra en la pantalla LCD y se evalúa contra el umbral.
- Si el peso es menor al límite, se enciende un LED de alerta.

# Tecnologías usadas:
Arduino UNO (simulado en Tinkercad)
Tinkercad para simulación de electrónica y sensores
Pantalla LCD 16x2
LED de alerta
FSR o celda de carga virtual

# Comunicación entre módulos:
Arduino lee los datos del sensor vía pin analógico.
Arduino envía información a la pantalla LCD a través de los pines digitales (RS, E, DB4-DB7).
Arduino activa el LED cuando detecta peso por debajo del umbral.
