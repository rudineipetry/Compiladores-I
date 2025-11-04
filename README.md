# Compiladores-I
# 🧩 Sistema de Varredura para C-

Este projeto implementa o **sistema de varredura (scanner)** da linguagem **C-**, conforme descrito no livro *Compiladores: Princípios e Práticas* de **Kenneth C. Louden**.

O programa lê um arquivo-fonte escrito em **C-** (`codigo.cminus`) e exibe na tela, para cada marca lida, o **tipo de token** e a **cadeia de caracteres (lexema)** correspondente.

---

## ⚙️ Como Executar

1. **Baixe ou clone** este repositório:

   ```bash
   git clone https://github.com/rudineipetry/Compiladores-I
   ```

2. **Certifique-se de ter o compilador GCC instalado** (caso queira recompilar o código).
   Se já quiser apenas executar, o arquivo **`scanner_cmenos.exe`** já está incluído.

3. **Abra o Prompt de Comando (CMD)** e navegue até a pasta onde o programa está salvo.
   Exemplo:

   ```bash
   cd C:\Users\ra190126\Downloads
   ```

4. **Execute o programa digitando:**

   ```bash
   scanner_cmenos.exe
   ```

   Pressione **Enter** e o sistema fará a varredura léxica.

---

## 🧾 Como indicar o código-fonte a ser varrido

O programa procura automaticamente um arquivo chamado **`codigo.cminus`** no mesmo diretório.
Basta abrir esse arquivo e alterar o conteúdo para o código C- que deseja analisar.

Exemplo de `codigo.cminus`:

```c
int x;
if (x < 10) x = x + 1;
```

---

## 💡 Saída esperada

Ao rodar o programa, você verá algo como:

```
===== Sistema de Varredura para C- =====

Tipo de Marca: INT             | Cadeia: int
Tipo de Marca: IDENTIFIER      | Cadeia: x
Tipo de Marca: SEMICOLON       | Cadeia: ;
Tipo de Marca: IF              | Cadeia: if
Tipo de Marca: LEFT_PAREN      | Cadeia: (
Tipo de Marca: IDENTIFIER      | Cadeia: x
Tipo de Marca: LESS            | Cadeia: <
Tipo de Marca: NUMBER          | Cadeia: 10
Tipo de Marca: RIGHT_PAREN     | Cadeia: )
Tipo de Marca: IDENTIFIER      | Cadeia: x
Tipo de Marca: ASSIGN          | Cadeia: =
Tipo de Marca: IDENTIFIER      | Cadeia: x
Tipo de Marca: PLUS            | Cadeia: +
Tipo de Marca: NUMBER          | Cadeia: 1
Tipo de Marca: SEMICOLON       | Cadeia: ;
Tipo de Marca: EOF             | Cadeia: 

===== Fim da Análise Léxica =====
```

---

## 🧠 Sobre

* Linguagem: **C**
* Autores: **Rudinei Petry Maggioni, João Lucas Dantas, João Gabriel Barbosa, Pedro Sant'ana Vendruscolo, Cristian Martinelle**
* Baseado na obra: *Kenneth C. Louden — Compiladores: Princípios e Práticas*
* Arquivo principal: `scanner_cmenos.c`
* Executável: `scanner_cmenos.exe`

---

📍 **Resumo:**
Entre no CMD, use o comando `cd` para navegar até a pasta do projeto, e digite:

```bash
scanner_cmenos.exe
```

Depois é só editar o arquivo `codigo.cminus` com o código que deseja analisar.
