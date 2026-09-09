# Sistema de riego automático con Arduino (Wokwi)

**Materia:** Desarrollo de Soluciones Informáticas 6to año
**Plataforma de simulación:** [Wokwi](https://wokwi.com/)

## Objetivo

Vas a armar, simular y programar un sistema que avisa con **tres LEDs** el estado de humedad de la tierra de una planta:

| LED | Color | ¿Qué indica? |
|---|---|---|
| Rojo | 🔴 | Tierra **seca** → hay que regar |
| Amarillo | 🟡 | Humedad **media** → atención, pronto va a necesitar agua |
| Verde | 🟢 | Tierra **húmeda** → está todo bien, no hace falta regar |

El sensor de humedad de tierra le manda al Arduino un valor analógico, y tu programa decide cuál de los tres LEDs prender según ese valor. En la simulación de Wokwi, ese sensor se representa con un **potenciómetro** (ver la aclaración en la Parte 1).

---

## Parte 1: Armar el circuito en Wokwi

1. Entrá a [wokwi.com](https://wokwi.com/) e iniciá sesión (podés usar tu cuenta de GitHub).
2. Hacé clic en **New Project → Arduino Uno**.
3. Con el botón **+** (Add component / Diagram), agregá los siguientes elementos:
   - 1 × **Potentiometer** (lo vamos a usar para *simular* el sensor de humedad de tierra — Wokwi no tiene un sensor de humedad real en su biblioteca, así que el potenciómetro cumple esa función: al girarlo, cambia el valor analógico igual que si la tierra estuviera más seca o más húmeda)
   - 3 × **LED** (vas a cambiarles el color: uno rojo, uno amarillo, uno verde)
   - 3 × **Resistor** (resistencia de 220 Ω — el valor se cambia haciendo clic sobre la resistencia una vez ubicada)

### Tabla de conexiones

| Componente | Pata / Pin | Conectar a |
|---|---|---|
| Potenciómetro | pata izquierda (GND) | GND del Arduino |
| Potenciómetro | pata derecha (VCC) | 5V del Arduino |
| Potenciómetro | pata del medio (wiper / señal) | **A0** del Arduino |
| Resistencia LED rojo | un extremo | ánodo (+) del LED rojo |
| Resistencia LED rojo | otro extremo | pin **10** del Arduino |
| LED rojo | cátodo (−) | GND |
| Resistencia LED amarillo | un extremo | ánodo (+) del LED amarillo |
| Resistencia LED amarillo | otro extremo | pin **9** del Arduino |
| LED amarillo | cátodo (−) | GND |
| Resistencia LED verde | un extremo | ánodo (+) del LED verde |
| Resistencia LED verde | otro extremo | pin **8** del Arduino |
| LED verde | cátodo (−) | GND |

> 💡 **Tip:** en cada LED, la pata **más larga** es el ánodo (+, va hacia la resistencia) y la pata **más corta** es el cátodo (−, va a GND). En el diagrama de Wokwi también podés confirmarlo pasando el mouse sobre cada pata.

> 💡 **¿Por qué un potenciómetro y no "el sensor" directamente?** Porque Wokwi no incluye un sensor de humedad de tierra real en su biblioteca de componentes. Para las prácticas de simulación, se usa un potenciómetro conectado igual que estaría conectado el sensor (GND, señal a A0, VCC): girándolo con el mouse durante la simulación, se obtiene el mismo efecto que tendría el sensor real al pasar de tierra seca a tierra húmeda. En un armado físico (fuera de la simulación), ahí sí usarías el sensor de humedad real, conectado de la misma forma (GND, AOUT a A0, VCC).

4. Revisá tu circuito contra la tabla antes de seguir. Si te falta una conexión, Wokwi no te va a dejar simular correctamente (o los LEDs no van a responder).



---

## Parte 2: Elegí el código correcto (opción múltiple)

Abajo tenés **cuatro versiones** del programa. Las cuatro *compilan* sin error, pero solo **una** hace exactamente lo que pide la consigna: prender el LED correspondiente según la humedad, sin que se prendan dos LEDs a la vez, usando los umbrales que se indican:

- Si `humedad > 600` → tierra seca → LED **rojo**
- Si `humedad` está entre `400` y `600` (inclusive) → humedad media → LED **amarillo**
- Si `humedad < 400` → tierra húmeda → LED **verde**

**Consigna:** leé las cuatro opciones, elegí cuál es la correcta y anotá en tu README de rama **por qué las otras tres están mal** (cada una tiene un error distinto).

### Opción A

```cpp
const int pinSensor = A0; // pin conectado al potenciómetro (simula el sensor)
const int pinRojo = 10;
const int pinAmarillo = 9;
const int pinVerde = 8;

void setup() {
  pinMode(pinRojo, OUTPUT);
  pinMode(pinAmarillo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int humedad = analogRead(pinSensor);
  Serial.println(humedad);

  if (humedad > 600) {
    digitalWrite(pinRojo, HIGH);
  }
  if (humedad >= 400 && humedad <= 600) {
    digitalWrite(pinAmarillo, HIGH);
  }
  if (humedad < 400) {
    digitalWrite(pinVerde, HIGH);
  }
  delay(500);
}
```

### Opción B

```cpp
const int pinSensor = A0; // pin conectado al potenciómetro (simula el sensor)
const int pinRojo = 10;
const int pinAmarillo = 9;
const int pinVerde = 8;

void setup() {
  pinMode(pinRojo, OUTPUT);
  pinMode(pinAmarillo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int humedad = analogRead(pinSensor);
  Serial.println(humedad);

  digitalWrite(pinRojo, LOW);
  digitalWrite(pinAmarillo, LOW);
  digitalWrite(pinVerde, LOW);

  if (humedad > 600) {
    digitalWrite(pinRojo, HIGH);
  } else if (humedad >= 400 && humedad <= 600) {
    digitalWrite(pinAmarillo, HIGH);
  } else if (humedad < 400) {
    digitalWrite(pinVerde, HIGH);
  }
  delay(500);
}
```

### Opción C

```cpp
const int pinSensor = A0; // pin conectado al potenciómetro (simula el sensor)
const int pinRojo = 10;
const int pinAmarillo = 9;
const int pinVerde = 8;

void setup() {
  pinMode(pinSensor, OUTPUT);
  pinMode(pinAmarillo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int humedad = analogRead(pinSensor);
  Serial.println(humedad);

  digitalWrite(pinRojo, LOW);
  digitalWrite(pinAmarillo, LOW);
  digitalWrite(pinVerde, LOW);

  if (humedad > 600) {
    digitalWrite(pinRojo, HIGH);
  } else if (humedad >= 400 && humedad <= 600) {
    digitalWrite(pinAmarillo, HIGH);
  } else if (humedad < 400) {
    digitalWrite(pinVerde, HIGH);
  }
  delay(500);
}
```

### Opción D

```cpp
const int pinSensor = A0; // pin conectado al potenciómetro (simula el sensor)
const int pinRojo = 10;
const int pinAmarillo = 9;
const int pinVerde = 8;

void setup() {
  pinMode(pinRojo, OUTPUT);
  pinMode(pinAmarillo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int humedad = analogRead(pinSensor);
  Serial.println(humedad);

  digitalWrite(pinRojo, LOW);
  digitalWrite(pinAmarillo, LOW);
  digitalWrite(pinVerde, LOW);

  if (humedad > 400) {
    digitalWrite(pinRojo, HIGH);
  } else if (humedad >= 600 && humedad <= 400) {
    digitalWrite(pinAmarillo, HIGH);
  } else if (humedad < 600) {
    digitalWrite(pinVerde, HIGH);
  }
  delay(500);
}
```



- Opción A: nunca apaga los LEDs que ya estaban prendidos de la lectura anterior. ¿Qué pasa si `humedad` pasa de 700 a 300?
- Opción C: hay un `pinMode` mal configurado, mirá bien el pin del sensor.
- Opción D: los umbrales están invertidos respecto de la consigna, y la condición del medio nunca se cumple.

</details>

---

## Parte 3: Simulá en Wokwi

1. Pegá el código que elegiste como correcto en el editor de Wokwi (pestaña `sketch.ino`).
2. Hacé clic en el botón ▶️ **Start Simulation**.
3. Hacé clic sobre la perilla del potenciómetro y arrastrala (girala) para simular distintos niveles de humedad.
4. Verificá:
   - Con el sensor "seco" (valor alto) → solo se prende el LED rojo.
   - Con un valor medio → solo se prende el LED amarillo.
   - Con el sensor "húmedo" (valor bajo) → solo se prende el LED verde.
   - Nunca se prenden dos LEDs al mismo tiempo.
5. Abrí el **Monitor Serie** (Serial Monitor) y confirmá que los valores que se imprimen tienen sentido con el LED que está prendido.

---

## Parte 4: Entrega con Git y GitHub (rama propia)

Este repositorio ya existe: lo vas a **clonar**, vas a trabajar en **tu propia rama**, y vas a subir tu archivo `.ino` ahí.

1. **Cloná el repositorio** en VS Code:
   - `Ctrl+Shift+P` → **Git: Clone** → pegá la URL de este repositorio → elegí carpeta → abrí la carpeta clonada.

2. **Creá tu rama**, con tu nombre y apellido (todo en minúsculas, sin espacios ni tildes, separado por guion):

   ```
   git checkout -b nombre-apellido
   ```

   Por ejemplo: `git checkout -b juan-perez`

3. **Creá tu archivo** `.ino` dentro del repositorio, nombrado igual que tu rama:

   ```
   nombre-apellido.ino
   ```

   Adentro pegá el código de la Opción que elegiste como correcta (ya simulada y probada en Wokwi).

4. **Guardá tus cambios** con los tres comandos, en este orden:

   ```
   git add .
   git commit -m "Agrego sistema de riego - nombre y apellido"
   git push -u origin nombre-apellido
   ```

5. Si te pide autenticarte en GitHub desde VS Code, seguí los pasos que te propone (inicio de sesión con tu cuenta).

6. Una vez que hiciste `push`, andá a GitHub y abrí un **Pull Request** desde tu rama hacia `main`, para que quede registrada tu entrega.

> **Importante:** no trabajes directamente sobre la rama `main`. Cada alumno trabaja en su propia rama, así no se pisan los archivos entre compañeros.

---

## Checklist de entrega

- [ ] Circuito armado en Wokwi con sensor + 3 LEDs (rojo, amarillo, verde) + 3 resistencias, según la tabla de conexiones
- [ ] Elegiste la opción de código correcta y explicaste por qué las otras tres estaban mal
- [ ] Simulaste el circuito y probaste los tres escenarios (seco / medio / húmedo)
- [ ] Creaste tu rama `nombre-apellido`
- [ ] Tu archivo `nombre-apellido.ino` está en el repositorio, en tu rama
- [ ] Hiciste `git add`, `git commit` y `git push` de tu trabajo
- [ ] Abriste el Pull Request de tu rama hacia `main`
