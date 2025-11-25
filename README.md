<div align="center">
  <!-- Banner with negative bottom margin -->
  <a href="https://github.com/BinRacer/pwn4heap">
    <img src="images/banner.svg" alt="pwn4heap" style="width:100%; max-width:100%; margin-top:0; margin-bottom:-0.5rem">
  </a>
</div>

---

## 📖 Overview

This repository presents an enhanced and practical extension of the renowned **how2heap** tutorial. While the original **how2heap** provides foundational examples of heap exploitation techniques in C, this project advances further by integrating production-ready Python Proof-of-Concept (PoC) exploits and modifying vulnerable programs to enable real-world shell acquisition capabilities.

The primary objective is to bridge the gap between theoretical vulnerability demonstrations and practical exploitation. Moving beyond simple proof-of-concepts that might only show control flow hijacking or arbitrary writes, this work focuses on achieving actual code execution in realistic contexts. This involves adapting the original **how2heap** examples to create exploitable conditions that can lead to shell access, thereby providing a more hands-on and impactful learning experience for understanding heap vulnerabilities.

## ✨ Features

- **Comprehensive Heap Exploitation**: Extends basic how2heap examples with practical implementations
- **Production-Ready PoCs**: Python-based exploits designed for real-world scenarios
- **Structured Learning**: Organized by glibc versions and exploitation techniques
- **Hands-On Approach**: Focuses on achieving actual shell execution rather than theoretical concepts

## 🛠️ Installation & Usage

### Prerequisites
Ensure you have the following installed on your system:
- Python 3
- GCC compiler
- Make utility
- Authorized testing environment

### Installation Steps

1. **Clone the repository**:
   ```shell
   git clone https://github.com/BinRacer/pwn4heap.git
   cd pwn4heap
   ```

2. **Install Python dependencies**:
   ```shell
   uv sync
   # pip install -r requirements.txt
   ```

3. **Install system dependencies**:
   ```shell
   sudo apt-get install gawk bison gcc-multilib g++-multilib -y
   ```

### Usage Guide

1. **Navigate to your desired technique**:
   ```shell
   cd src/2.23/unsorted_bin_leak
   ```

2. **Synchronize and adjust parameters** in the Python exploit file before rebuilding the binary

3. **Rebuild and execute**:
   ```shell
   make rebuild
   python exploit.py
   ```

## 📁 Project Structure

```
pwn4heap
├── Disclaimer.md                       # Legal Compliance
├── LICENSE
├── pyproject.toml                      # Python dependencies
├── README.md
├── requirements.txt                    # Python dependencies
├── src
│   └── 2.23                            # Techniques for glibc 2.23
│       ├── binary                      # binary files for glibc 2.23
│       ├── fast_bin_attack
│       ├── fast_bin_attack_bss
│       ├── house_of_apple_one
│       ├── house_of_apple_two
│       ├── house_of_banana
│       ├── house_of_corrosion
│       ├── house_of_einherjar
│       ├── house_of_emma
│       ├── house_of_emma_again
│       ├── house_of_force
│       ├── house_of_fun
│       ├── house_of_husk
│       ├── house_of_husk_again
│       ├── house_of_kiwi
│       ├── house_of_kiwi_again
│       ├── house_of_lore
│       ├── house_of_mind_fastbin
│       ├── house_of_obstack
│       ├── house_of_orange
│       ├── house_of_pig
│       ├── house_of_pig_again
│       ├── house_of_rabbit
│       ├── house_of_roman
│       ├── house_of_spirit
│       ├── house_of_storm
│       ├── large_bin_attack
│       ├── large_bin_attack_again
│       ├── overlapping_chunks
│       ├── poison_null_byte
│       ├── sysmalloc_int_free
│       ├── unsafe_unlink
│       ├── unsorted_bin_attack
│       ├── unsorted_bin_attack_again
│       ├── unsorted_bin_attack_bss
│       └── unsorted_bin_leak
└── uv.lock
```

## ⚠️ Important Notes

- **Legal Compliance**: Always ensure you have proper authorization before testing any security vulnerabilities
- **Environment Isolation**: Conduct testing in controlled, isolated environments to prevent unintended system impacts
- **Educational Purpose**: This material is intended for educational and authorized security research only

For complete legal information and disclaimers, please refer to the [Disclaimer](./Disclaimer.md) document.

---

<div align="center">
  <sub>Built with ❤️ for the security research community</sub>
</div>
