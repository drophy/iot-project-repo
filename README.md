
# Punto Medio

Este repositorio tiene como objetivo centralizar el código 
utilizado en nuestro proyecto final de IoT (Punto Medio).

- [ESP32](https://github.com/drophy/iot-project-repo#c%C3%B3digo-para-el-ESP32)
- [AWS Lambda](https://github.com/drophy/iot-project-repo#c%C3%B3digo-de-aws-lambda)
- [App Móvil](https://github.com/drophy/iot-project-repo#app-m%C3%B3vil)


## Código para el ESP32
El código programa a un microcontrolador **ESP32 con capacidad GSM** 
para que pueda recibir mensajes SMS y en caso de que este 
contenga el texto "Locker 2A" pone en `LOW` por 3 segundos el pin
correspondiente a ese locker y después retorna a `HIGH`. Esto con
el fin de desbloquear temporalmente el locker. 

El código incluye una función para enviar mensajes SMS que 
actualmente no se está utilizando, pero podría ser útil a futuro.



## Código de AWS Lambda
Tiene como rol recibir peticiones de la app móvil y enviarlas
a Twilio. El código se encuentra en la carpeta "AWS Lambda" 
en este repositorio. 

### Setup
El archivo `local.js` permite hacer pruebas en un entorno local,
mientras que el archivo `index.js` junto con la carpeta 
`node_modules` (se debe correr `npm install`) y los archivos
.json son los que se utilizan para crear el .zip que se sube a
AWS Lambda.

Se requieren las siguientes variables de entorno ya sea en un
archivo `.env` (local) o configuradas en AWS Lambda.

`ACCOUNT_SID`

`AUTH_TOKEN`

`TWILIO_PHONE`

`TARGET_PHONE`

Las primeras 3 se obtienen de una cuenta de Twilio. 
`TARGET_PHONE` únicamente se utiliza en la prubea local; en
AWS Lambda se accede como `event.target`. Los números de teléfono
los utilizamos con el '+' al principio y sin espacios intermedios.

### API

#### Mandar SMS

```http
  POST /locker-sms
```

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `target`  | `string` | **Requerido**. Teléfono al que se enviará el SMS |
| `message`  | `string` | **Requerido**. Mensaje a enviar |


## App Móvil
Optamos por mantener el código de la app móvil en un repositorio
adicional: https://github.com/franciscogonzalez08/puntoMedioIoT

### Setup
Únicamente se debe clonar el repositorio, instalar los 
paquetes del `pubspec.yaml` (en VS Code basta con utilizar
`Ctrl + S` en el archivo) y correr el código en un emulador
o celular. Se recomienda tener las extensiones *Dart* y 
*Flutter* para VS Code.

### Referencia de colores
| Color             | Hex                                                                |
| ----------------- | ------------------------------------------------------------------ |
| Nav Color         | ![#009688](https://via.placeholder.com/10/009688?text=+) 0xFF009688 |
| Header Color      | ![#4DB6AC](https://via.placeholder.com/10/4DB6AC?text=+) 0xFF4DB6AC |
| Button Color1     | ![#1CD8D2](https://via.placeholder.com/10/1CD8D2?text=+) 0xFF1CD8D2 |
| Button Color2     | ![#FFFFFF](https://via.placeholder.com/10/FFFFFF?text=+) 0xFFE5E5E5 |
| Card Color        | ![#E5E5E5](https://via.placeholder.com/10/E5E5E5?text=+) 0xFFE5E5E5 |
