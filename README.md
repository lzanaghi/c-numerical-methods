# 📐 Numerical Methods – FACENS

Welcome to the repository for the **Numerical Methods** course at *Faculdade de Engenharia de Sorocaba (FACENS)*.  
This repository contains several C implementations of fundamental algorithms used in numerical analysis.

All programs are written in **C** and are fully modular, using functions and pointers.  
They are designed for **educational purposes**, making it easier to understand each algorithm step-by-step.

---

## 📚 Contents

This repository includes the following numerical methods:

| Category               | Algorithms Implemented                                      |
|------------------------|-------------------------------------------------------------|
|🧮 Root-finding         | Bisection Method (a.k.a. Dichotomy)                         |
|📈 Polynomial Interpolation | Lagrange Interpolation                               |
|🧾 Numerical Integration | Trapezoidal Rule, Simpson's Rule                         |
|🔢 Linear Systems       | Gauss Elimination, LU Decomposition                        |

---

## 🚀 How to Use

Each algorithm is implemented as a standalone `.c` file with clear instructions and comments.

### 📌 General Instructions:

1. Clone or download the repository:
   ```bash
   git clone https://github.com/your-username/numerical-methods-facens.git
   ```

2. Compile the desired algorithm using a C compiler, for example:
   ```bash
   gcc bisection.c -o bisection -lm
   ```

3. Run the compiled executable:
   ```bash
   ./bisection
   ```

4. Follow the on-screen prompts to enter function coefficients, intervals, or matrix values depending on the algorithm.

---

## ✅ Checklist

| Algorithm                            | Status    | File                 |
|-------------------------------------|-----------|----------------------|
| Bisection Method (Root-finding)     | ✅ Done   | `bisection.c`        |
| Lagrange Interpolation              | ⬜ Coming | `lagrange.c`         |
| Trapezoidal Rule (Integration)      | ⬜ Coming | `trapezoidal.c`      |
| Simpson’s Rule (Integration)        | ⬜ Coming | `simpson.c`          |
| Gauss Elimination (Linear Systems)  | ⬜ Coming | `gauss_elimination.c`|
| LU Decomposition (Linear Systems)   | ⬜ Coming | `lu_decomposition.c` |

> Each file will include instructions, modular code, and examples to guide the user.

---

## 📌 Notes

- All code is **commented and structured** with readability in mind.
- Make sure to **link the math library (`-lm`)** when compiling, as many functions use `math.h`.
- Contributions and improvements are welcome, especially for testing edge cases and numerical stability.

---

## 👨‍🎓 Author

Developed by **[Ronaldo Simeone]**  
FACENS – Engenharia da Computação

---

## 📄 License

This project is licensed for educational use only. Commercial or unauthorized distribution is not permitted.
