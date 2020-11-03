# TP2: Verificador eBPF

## Ezequiel Zbogar - 102216

### Taller de Programación I

Diagrama con las principales clases del trabajo practico:

![Class Diagram](https://github.com/ezezbogar/TP2-Taller/blob/main/Images/Class-Diagram.png)

![Sequence Diagram](https://github.com/ezezbogar/TP2-Taller/blob/main/Images/Sequence-Diagram.png)

Tanto las clases "Result" y "Repository estan implementadas como un monitor, esto es, cuentan con un mutex para que solo pueda acceder un threads a la vez y de esta forma evitar race conditions

- Link al repositorio de GitHub: https://github.com/ezezbogar/TP2-Taller