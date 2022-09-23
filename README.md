# Desafio 3

Now things will start getting more complicated. 

Task: Find the first 21-digit palindromic prime contained in the decimal expansion of π (3,1415…)

Hint: You may want to use the source  https://pi.delivery/ to get the largest prime calculation that has 100 trillion digits. 

You may use whichever programming language that you want and you will be required to provide your code after submitting the right number in the form below. 

Attention: You can only submit 3 times. Double check your answer before submitting

```
$ gsutil -m rsync -R gs://pi100t ./
```

# links do número Pi

- [Pi index](https://storage.googleapis.com/pi100t/index.html)
- [Pi - Dec - Chudnovsky - 0.ycd](https://storage.googleapis.com/pi100t/Pi%20-%20Dec%20-%20Chudnovsky/Pi%20-%20Dec%20-%20Chudnovsky%20-%200.ycd)
- [Pi - Dec - Chudnovsky - 1.ycd](https://storage.googleapis.com/pi100t/Pi%20-%20Dec%20-%20Chudnovsky/Pi%20-%20Dec%20-%20Chudnovsky%20-%201.ycd)
- [Pi - Dec - Chudnovsky - 2.ycd](https://storage.googleapis.com/pi100t/Pi%20-%20Dec%20-%20Chudnovsky/Pi%20-%20Dec%20-%20Chudnovsky%20-%202.ycd)
- ...

# Extrair Número Pi

## DigitViewer

Baixar e compilar o [DigitViewer](https://github.com/Mysticial/DigitViewer)

Para compilar: `../DigitViewer/VSS - DigitViewer2/Compile-Linux.sh`, vai criar a pasta `Binaries`

## Extrair número Pi para txt

### Executar:

`cd /home/emerson/Desktop/eme/projetos/digitviewer/DigitViewer/VSS\ -\ DigitViewer2/Binaries/;./Digit\ Viewer\ -\ 05-A64`

### Informar o arquivo de interesse:

`/home/emerson/Documents/pi_files/Pi - Dec - Chudnovsky - 0.ycd`

### Selecione a opção `2`


| Arquivo | Range Inicial    | Range Final    |
| :---:   | :---: | :---: |
| Pi - Dec - Chudnovsky - 0.ycd | 1   | 100000000000   |
| Pi - Dec - Chudnovsky - 1.ycd | 100000000001   | 200000000000   |
| Pi - Dec - Chudnovsky - 2.ycd | 200000000001   | 300000000000   |
| ... | ...    | ...    |

O range inicial e final depende do arquivo de interesse:

- `Pi - Dec - Chudnovsky - 0.ycd`: de `1` a `100000000000`
- `Pi - Dec - Chudnovsky - 1.ycd`: de `100000000001` (100000000000 + 1) a `200000000000`
- `Pi - Dec - Chudnovsky - 2.ycd`: de `200000000001` (200000000000 + 1) a `300000000000`

**OBS**: Caso sejam informados valores maiores ou menores, o [DigitViewer](https://github.com/Mysticial/DigitViewer) vai usar os arquivos anteriores ou subsequentes, senão encontrar gera uma exceção.

### O arquivo de saída:

`/home/emerson/Documents/pi_files/saida0.txt`

### Para visualizar os 50 primeiros:

`head -c 50 /home/emerson/Documents/pi_files/saida0.txt`

# urls

- [sigmageek parte 3](https://sigmageek.com/solution/find-large-palindromic-prime-numbers-in-the-decimal-expansion-of-%CF%80-31415%E2%80%A6-1656603146901x235034290182684670)
- [pi.delivery](https://pi.delivery/)
- [pi2e](https://pi2e.ch/blog/2017/03/10/pi-digits-download/#download)
- [api](https://api.pi.delivery/v1/pi?start=100000000000000&numberOfDigits=100&radix=10)
- [DigitViewer](https://github.com/Mysticial/DigitViewer)

# discussões

- [issues](https://github.com/Mysticial/y-cruncher/issues)
- [DigitViewer Fórum 1](https://github.com/Mysticial/y-cruncher/issues/19)
