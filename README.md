
# Punto Medio

Este repositorio tiene como objetivo centralizar el código 
utilizado en nuestro proyecto final de IoT (Punto Medio).

## App Móvil
Optamos por mantener el código de la app móvil en un repositorio
adicional: https://github.com/franciscogonzalez08/puntoMedioIoT

## Código de AWS Lambda
Tiene como rol recibir peticiones de la app móvil y enviarlas
a Twilio. El código se encuentra en la carpeta "AWS Lambda" 
en este repositorio. 

El archivo `local.js` permite hacer pruebas en un entorno local,
mientras que el archivo `index.js` junto con la carpeta 
`node_modules` (se debe correr `npm install`) y los archivos
.json son los que se utilizan para crear el .zip que se sube a
AWS Lambda.

Se requieren las siguientes variables de entorno ya sea en un
archivo `.env` (local) o configuradas en AWS Lambda

`ACCOUNT_SID`

`AUTH_TOKEN`

`TWILIO_PHONE`

`TARGET_PHONE`

Las primeras 3 se obtienen de una cuenta de Twilio. Los 
números de teléfono los utilizamos con el '+' al principio y 
sin espacios intermedios.

## Código para el [MODELO DEL MICRO]
TODO


