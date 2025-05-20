.data
array:
.dword 0x64, 0xc8, 0x12c
f:
.dword 1
g:
.dword 2
h:
.dword 3
i:
.dword 4
j:
.dword 5

f3:
.dword 4
j3:
.dword 5
.text
//1.a)
    ldr X0, f
    ldr X1, g
    ldr X2, h
    ldr X3, i
    ldr X4, j
    add X0, X1, X2
    add X0, X0, X3
    add X0, X0, X4
//1.b)
    ldr X0, f
    ldr X1, g
    ldr X2, h
    add X0, X2, #5
    add X0, X0, X1
//1.c)
    ldr X0, f
    ldr X1, g
    ldr X2, h
    add X0, X1, X2
    add X0, X0, X0

/*Luego, dadas las siguientes sentencias en assembler LEGv8:
a)  ADD X0, X1, X2
b)  ADDI X0, X0, #1
    ADD X0, X1, X2
f=>1 ,g=2 ,h=>3 ,i=>4 ,j=>5.
2.1) Escribir la secuencia mínima de código “C” asumiendo que los registros X0, X1 y X2
contienen las variables f, g y h respectivamente.
a)  ADD X0, X1, X2
    ===> f = g + h => f = 2 + 3 = 5
b)  ADDI X0, X0, #1
    ADD X0, X1, X2
 ===> f= f + 1 => f = g + h => f = 2 + 3 = 5
2.2) Dar el valor de cada variable en cada instrucción assembler si f, g y h se inicializan
con valores de 1, 2, 3, en base 10, respectivamente.
a)ADD X0, X1, X2   ; X0 = 2 + 3 = 5
| Instrucción | X0 | X1 | X2 |
| ----------- | -- | -- | -- |
| Inicial     | 1  | 2  | 3  |
| ADD         | 5  | 2  | 3  |
b)ADDI X0, X0, #1  ; X0 = 1 + 1 = 2
  ADD  X0, X1, X2  ; X0 = 2 + 3 = 5  ← pisa el valor anterior
| Instrucción | X0 | X1 | X2 | X3 | X4 |
| ----------- | -- | -- | -- |
| ADDI        | 2  | 2  | 3  |
| ADD         | 5  | 2  | 3  |
*/
/* Ej3 -> XZR = 0 X0 -> 4, X1 -> 5
3.A) F=-G-F=-(G+F)
*/
    ldr X0, f3
    ldr X1, j3
    add X0, X0, X1  // F = G + F = 4 + 5 = 9
    sub X0, XZR, X0 // F = 0 - F = 0 - 9 = -9

/*
| Instrucción   | X0 | X1 | XZR | X0(final) |
| ------------- | -- | -- | ----| --------- |
| add x0,x0,x1  | 4  | 5  |    0|     9     |
| sub x0,xzr,x0 | 9  | 5  |    0|    -9     |
 */

/*
3.B) F = G +(-F-5)=G -(F+5)
*/
    ldr X0, f3
    ldr X1, j3
    add X0, X0, #5 // F = F + 5 = 4 + 5 = 9
    sub X0, XZR, X0 // F = 0 - F = 0 - 9 = -9
    add X0, X0, X1 // F = G - F = 5 - 9 = -4
/*
| Instrucción   | X0 | X1 | XZR | X0(final) |
| ------------- | -- | -- | ----| --------- |
| add x0,x0,#5  | 4  | 5  |    0|     9     |
| sub x0,xzr,x0 | 9  | 5  |    0|    -9     |
| add x0,x0,x1  | -9 | 5  |    0|    -4     |
 */

/*  Ej4
a)  SUB X1, XZR, X1
    ADD X0, X1, X2
b)  ADDI X2, X0, #1
    SUB X0, X1, X2
4.1) Escribir la secuencia mínima de código “C” asumiendo que los registros X0, X1, y X2
contienen las variables f, g, y h respectivamente.
a) F=-g+h
b) F = g + (f + 1)
4.2) Dar el valor de cada variable en cada instrucción assembler si f, g, y h se inicializan
con valores de 1, 2 y 3, en base 10 respectivamente.
a)
| Instrucción      | X0 | X1 | X2 | XZR | X0(final) | X1(final) | X2(final) |
| ---------------- | -- | -- | -- | --  | --------- | --------- | --------- |
| SUB X1, XZR, X1  | 1  | 2  |  3 |  0  |     1     |    -2     |    3      |
| ADD X0, X1, X2   | 1  | -2 |  3 |  0  |     1     |    -2     |    3      |
b)
| Instrucción      | X0 | X1 | X2 | XZR | X0(final) | X1(final) | X2(final) |
| ---------------- | -- | -- | -- | --  | --------- | --------- | --------- |
| ADDI X2, X0, #1  | 1  | 2  |  3 |  0  |     1     |    -2     |    2      |
| SUB  X0, X1, X2  | 1  | 2  |  2 |  0  |     0     |     1     |    2      |
 */

    /*
    Ej5:
        a) f = -g - A[4];
        b) B[8] = A[i - j];
    5.1) Escribir la secuencia mínima de código assembler LEGv8 asumiendo que f, g, i y j
    se asignan en los registros X0, X1, X2 y X3 respectivamente, y que la dirección base de
    los arreglos A y B se almacenan en los registros X6 y X7 respectivamente.
    */

    ldr X0, f // X0 = 1
    ldr X1, g // X1 = 2
    ldr X2, i // X2 = 4
    ldr X3, j // X3 = 5
    ldr X6, =array

/*
5.2) ¿Cuántos registros se utilizan para llevar a cabo las operaciones anteriores?
    R: Un total de 9 registros.
 */

end:
infloop:
    b infloop

/* Solucion chatGPT:
    // f = -g - A[4]
        sub X9, XZR, X1 // X9 = -g
        ldur X10, [X6, #32]// X10 = A[4]
        sub X0, X9, X10 // X0 = -g - A[4]
    // B[8] = A[i - j]
        sub X9, X2, X3 // X9 = i - j
        lsl X9, X9, #3      // X9 = (i - j) * 8
        add X9, X6, X9      // X9 = &A[i - j]
        ldur X10, [X9, #0]  // X10 = A[i - j]
        add X11, X7, #64    // X11 = &B[8]
        stur X10, [X11, #0] // B[8] = A[i - j]
*/
