# 🚧 En Desarrollo 🚧

## Índice

1. [Introducción](#memorizar-palabras-del-latín)
2. [Compatibilidad](#compatibilidad)
   - [Sistema Operativo](#sistema-operativo)
   - [Macrones](#macrones)
3. [Cómo Usarlo](#cómo-usarlo)
   - [1. Descargar el código](#1-descargar-el-código)
   - [2. Abrir la Consola o Terminal](#2-abrir-la-consola-o-terminal)
   - [3. Ejecutar el programa](#3-ejecutar-el-programa)


# Memorizar Palabras del Latín

**Un programa sencillo para aprender palabras en latín desde la consola**. El programa incluye sustantivos, adjetivos, verbos... La gran ventaja es que puedes ver las **declinaciones** o **conjugaciones** de cada palabra. Es un como un juego donde puedes seleccionar cualquier tipo de modo de juego, adivinar la palabra traducida, el genero, la declinación *et cētera*. También incluye un pequeño diccionario, y permite al usuario añadir otras colecciones de palabras.

## Compatibilidad
### Sistema Operativo
El programa funciona correctamente para `Windows 10`, no es seguro que funcione en otros sistemes operativos como `Linux` o `Mac`. Esto se debe especialmente por la compatibilidad de la terminal con caracteres especiales.

### Macrones
Para usar el programa es necesario poder escribir macrones (āēīōūȳ), para esto se recomienda usar programas como `autohotkey` con el siguiente _script_:
```
; Mayúsculas
!+a::Send, Ā
!+e::Send, Ē
!+i::Send, Ī
!+o::Send, Ō
!+u::Send, Ū
!+y::Send, Ȳ

; Minúsculas
!a::Send, ā
!e::Send, ē
!i::Send, ī
!o::Send, ō
!u::Send, ū
!y::Send, ȳ
```
De esta forma se pueden escribir macrones con `alt + VOCAL`.

## Cómo Usarlo

### 1. Descargar el código
Primero, descarga el código completo y guárdalo en la carpeta que prefieras. Por ejemplo:  
```
C:\codigos\Memorizar-Latin
```

### 2. Abrir la Consola o Terminal
Abre la consola o terminal en tu sistema operativo. Una vez abierta, navega hasta la carpeta donde has descargado el código con el siguiente comando:  
```
cd C:\codigos\Memorizar-Latin
```

### 3. Ejecutar el programa
Para ejecutar el programa, escribe el siguiente comando y pulsa `Enter`:
```
./main
```
