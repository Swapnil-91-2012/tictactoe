
---

# 🎮 Tic Tac Toe (Standard & Pro Mode) – C Console Game

A feature-rich **Tic Tac Toe game written in C**, designed for two players and played entirely in the console. The game supports **two gameplay modes**, maintains a **scoreboard**, and provides an enhanced **Pro Mode** with a dynamic move queue.

---

## 🚀 Features

### 🟢 Standard Mode

* Classic 3×3 Tic Tac Toe gameplay
* Players take turns placing **X** and **O**
* A match can end in:

  * Win → **+10 points**
  * Draw → **0 points**

### 🔵 Pro Mode

* Advanced gameplay with a **move queue system**
* After 6 moves, older moves are replaced dynamically
* Encourages strategy beyond traditional Tic Tac Toe
* Win → **+20 points**
* No draws (game continues until a win)

### 📊 Scorecard System

* Scores persist across multiple rounds
* Separate scores for both players
* Final scorecard displayed on exit

### 👥 Two-Player Support

* Custom player names
* Choice of starting mark (X or O)

---

## 🧠 Game Rules

### Standard Mode

* First player to align **3 marks** horizontally, vertically, or diagonally wins
* Game ends in a draw if the board fills with no winner

### Pro Mode

* Each player can have **only 3 active moves** on the board
* Older moves are automatically removed once the queue is full
* Board remains dynamic until a winner is decided

---

## 🛠️ How the Program Works

* `drawBoard()` → Displays the game board and mode
* `inputStandard()` → Handles Standard Mode input
* `inputPRO()` → Handles Pro Mode input with queue logic
* `checkWin()` → Checks win/draw conditions
* `standardMode()` & `proMode()` → Game flow controllers
* `displayScoreCard()` → Displays current scores

---

## ▶️ How to Compile and Run

### Compile

```bash
gcc tic_tac_toe.c -o tic_tac_toe
```

### Run

```bash
./tic_tac_toe
```

> ⚠️ Note:
> This program uses `system("cls")`, which works on **Windows**.
> For Linux/macOS, replace `cls` with `clear`.

---

## 🧩 Controls

* Enter a number **1–9** to place your mark
* Follow on-screen prompts to choose:

  * Game mode
  * Player marks
  * Moves

---

## 📌 Scoring System

| Mode          | Win Points | Draw | Loss |
| ------------- | ---------- | ---- | ---- |
| Standard Mode | 10         | 0    | 0    |
| Pro Mode      | 20         | —    | 0    |

---

## 📂 Project Structure

```
tic_tac_toe.c
README.md
```

---

## ✨ Future Improvements (Optional)

* Single-player mode (AI)
* Colorized console output
* Undo functionality
* Save/load game state
* Cross-platform screen clearing

---

## 👨‍💻 Author

Developed as a **C programming console project** to demonstrate:

* Arrays & matrices
* Game logic
* User input handling
* Modular programming

---

