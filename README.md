<div align="center">
  <a href="https://github.com/BinRacer/pwn4heap">
    <img src="images/banner.svg" alt="pwn4heap" style="width:100%; max-width:100%; margin-top:0; margin-bottom:-0.5rem">
  </a>

  <p>
    <a href="./README.md">English</a> | <a href="./README.zh-CN.md">简体中文</a>
  </p>

  <p>
    Hands-on heap exploitation labs — Python PoCs across glibc 2.23 through 2.39.
  </p>

  <p>
    <a href="./LICENSE"><img src="https://img.shields.io/badge/License-MIT-blue.svg" alt="License: MIT"></a>
    <a href="#glibc-matrix"><img src="https://img.shields.io/badge/glibc-2.23%20%7C%202.27%20%7C%202.31%20%7C%202.35%20%7C%202.39-informational" alt="glibc versions"></a>
  </p>
</div>

---

## Overview

`pwn4heap` is a Python-based rework of the well-known **how2heap** tutorial. Where the original demonstrates each heap exploitation technique through C snippets, this project re-implements every technique as a self-contained Python PoC, so the exploit logic is easier to read, modify, and reuse against a real target.

Each technique comes with its own vulnerable program, built against a specific glibc version and linked to a custom glibc toolchain under `/opt/glibc`.

Every lab is self-contained and reproducible, shipping with:

- a vulnerable program and its source, built against a specific glibc version;
- a Python exploit PoC targeting that program;
- a `Makefile` with a `rebuild` target;
- a per-version `README.md` listing all techniques for that glibc branch.

> Intended for authorized security research and education only. See [Disclaimer](./Disclaimer.md).

---

## Repository Structure

```text
pwn4heap/
├── Disclaimer.md
├── LICENSE
├── README.md
├── README.zh-CN.md
├── ProjectStructure.md
├── References.md
├── pyproject.toml
├── requirements.txt
├── uv.lock
├── images/
│   └── banner.svg
├── binary/
│   ├── Makefile              # forwards to <version>/Makefile
│   └── <version>/            # one of: 2.23, 2.27, 2.31, 2.35, 2.39
│       ├── <NN>/             # binary target; NN counts per version (see below)
│       └── Makefile          # forwards to <NN>/Makefile
└── src/
    └── <version>/
        ├── <technique>/      # exploit.py + flag
        └── README.md         # per-version technique index
```

| Version | Binary targets | Technique highlights                                                                                                                                                   |
| ------- | -------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 2.23    | `01` … `18`    | Pre-tcache era: `house_of_*`, `unsorted_bin_*`, `large_bin_attack`, `fast_bin_attack`, `overlapping_chunks`, `poison_null_byte`, `sysmalloc_int_free`, `unsafe_unlink` |
| 2.27    | `01` … `21`    | Adds `tcache_*`, `fast_bin_reverse_into_tcache`, `house_of_atum`, `house_of_botcake`, `house_of_tangerine`, `sysmalloc_int_free_again`                                 |
| 2.31    | `01` … `19`    | Adds `house_of_io`; extends `house_of_einherjar`, `house_of_lore`, `sysmalloc_int_free`, `tcache_stashing_unlink_attack`                                               |
| 2.35    | `01` … `11`    | Adds `house_of_emma_one` … `four`; drops pre-tcache-only variants                                                                                                      |
| 2.39    | `01` … `09`    | Adds `house_of_snake`; latest tcache and large-bin hardening                                                                                                           |

> `*` denotes multiple numbered or suffixed variants (e.g. `house_of_apple_one` … `house_of_apple_eight`, `house_of_emma_one` … `house_of_emma_four`). Each `src/<version>/README.md` lists the exact set for that branch.

---

## Lab Anatomy

### Technique directory

Each technique lives in its own folder under `src/<version>/`:

```text
<technique>/
├── exploit.py            # Python PoC for this technique
└── flag                  # flag file (proves successful exploitation)
```

### Binary directory

Each glibc version also ships a `binary/` directory with numbered variants used as targets:

```text
binary/<version>/
├── 01/
│   ├── binary            # compiled vulnerable program
│   ├── binary.bndb       # Binary Ninja database
│   ├── binary.c          # source
│   ├── ld-2.XX.so        # matching dynamic linker
│   ├── ld-linux-x86-64.so.2 -> ld-2.XX.so
│   ├── libc-2.XX.so      # matching libc
│   ├── libc.so.6 -> libc-2.XX.so
│   └── Makefile
├── 02/
├── ...
└── NN/
```

- Every `binary/<version>/NN/` ships a prebuilt executable, its source, and the matching `ld` / `libc`.
- Binaries are linked against `/opt/glibc/<version>/amd64/`, so they run as-is once the corresponding toolchain is installed (see [Prebuilt glibc Toolchain](#prebuilt-glibc-toolchain)).
- Makefile hierarchy:
    - `binary/Makefile` forwards `all` / `clean` / `rebuild` / `help` to each `<version>/Makefile`;
    - `<version>/Makefile` forwards the same targets to the numbered subdirectories;
    - `<version>/NN/Makefile` rebuilds the binary against `/opt/glibc/<version>/amd64`.

---

## Prebuilt glibc Toolchain

The repository relies on custom glibc builds installed under `/opt/glibc`. Prebuilt tarballs for each supported version are available on the [Releases](https://github.com/BinRacer/pwn4heap/releases) page:

| Version | Download                                                                                                             |
| ------- | -------------------------------------------------------------------------------------------------------------------- |
| 2.23    | [glibc-2.23_amd64.tar.xz](https://github.com/BinRacer/pwn4heap/releases/download/glibc_2.23/glibc-2.23_amd64.tar.xz) |
| 2.27    | [glibc-2.27_amd64.tar.xz](https://github.com/BinRacer/pwn4heap/releases/download/glibc_2.27/glibc-2.27_amd64.tar.xz) |
| 2.31    | [glibc-2.31_amd64.tar.xz](https://github.com/BinRacer/pwn4heap/releases/download/glibc_2.31/glibc-2.31_amd64.tar.xz) |
| 2.35    | [glibc-2.35_amd64.tar.xz](https://github.com/BinRacer/pwn4heap/releases/download/glibc_2.35/glibc-2.35_amd64.tar.xz) |
| 2.39    | [glibc-2.39_amd64.tar.xz](https://github.com/BinRacer/pwn4heap/releases/download/glibc_2.39/glibc-2.39_amd64.tar.xz) |

Install them with:

```bash
sudo mkdir -p /opt/glibc/
cd /opt/glibc
sudo tar -xJvf glibc-2.23_amd64.tar.xz
sudo tar -xJvf glibc-2.27_amd64.tar.xz
sudo tar -xJvf glibc-2.31_amd64.tar.xz
sudo tar -xJvf glibc-2.35_amd64.tar.xz
sudo tar -xJvf glibc-2.39_amd64.tar.xz
```

After extraction, each version lives under `/opt/glibc/<version>/amd64/`, the path expected by the shipped binaries and their `Makefile`s. No additional configuration is required.

---

## glibc Matrix

Techniques are grouped by the glibc version they target. Newer glibc releases introduce new mitigations and, in turn, new techniques.

| Branch | Targets     | Focus                                                                             |
| ------ | ----------- | --------------------------------------------------------------------------------- |
| 2.23   | `01` … `18` | Pre-tcache era: fastbin, unsorted bin, large bin, house of *, unsafe unlink, etc. |
| 2.27   | `01` … `21` | tcache introduction: tcache poisoning, tcache stashing unlink, tcache metadata    |
| 2.31   | `01` … `19` | Refined tcache and safe-linking era techniques (house of botcake, house of io, …) |
| 2.35   | `01` … `11` | Modern tcache hardening; house of emma family; house of tangerine                 |
| 2.39   | `01` … `09` | Latest hardening; house of snake; updated tcache and large bin variants           |

> Only source, Makefiles, and prebuilt binaries are shipped. Each `binary/<version>/NN/` directory contains the exact `ld` and `libc` needed to run the target.

---

## Technique Index

Each glibc version has its own index at the top of its directory, listing every technique with a direct link to the corresponding `exploit.py`:

| Version | Index                                      |
| ------- | ------------------------------------------ |
| 2.23    | [src/2.23/README.md](./src/2.23/README.md) |
| 2.27    | [src/2.27/README.md](./src/2.27/README.md) |
| 2.31    | [src/2.31/README.md](./src/2.31/README.md) |
| 2.35    | [src/2.35/README.md](./src/2.35/README.md) |
| 2.39    | [src/2.39/README.md](./src/2.39/README.md) |

The table below summarizes which techniques are available in each glibc branch, ordered roughly from simpler to more advanced.

| Tech                          | 2.23 | 2.27 | 2.31 | 2.35 | 2.39 |
| ----------------------------- | :--: | :--: | :--: | :--: | :--: |
| unsorted_bin_leak             |  ✅  |  ✅  |  ✅  |  ✅  |  ✅  |
| fast_bin_attack               |  ✅  |  ✅  |  ✅  |  ❌  |  ❌  |
| fast_bin_attack_bss           |  ✅  |  ✅  |  ✅  |  ✅  |  ✅  |
| unsorted_bin_attack           |  ✅  |  ✅  |  ❌  |  ❌  |  ❌  |
| large_bin_attack              |  ✅  |  ✅  |  ✅  |  ✅  |  ✅  |
| overlapping_chunks            |  ✅  |  ✅  |  ✅  |  ✅  |  ✅  |
| poison_null_byte              |  ✅  |  ✅  |  ✅  |  ✅  |  ✅  |
| unsafe_unlink                 |  ✅  |  ✅  |  ✅  |  ✅  |  ✅  |
| house_of_spirit               |  ✅  |  ✅  |  ✅  |  ✅  |  ✅  |
| house_of_lore                 |  ✅  |  ✅  |  ✅  |  ✅  |  ✅  |
| house_of_force                |  ✅  |  ✅  |  ❌  |  ❌  |  ❌  |
| house_of_rabbit               |  ✅  |  ✅  |  ❌  |  ❌  |  ❌  |
| house_of_roman                |  ✅  |  ✅  |  ❌  |  ❌  |  ❌  |
| house_of_storm                |  ✅  |  ✅  |  ❌  |  ❌  |  ❌  |
| house_of_orange               |  ✅  |  ❌  |  ❌  |  ❌  |  ❌  |
| house_of_pig                  |  ✅  |  ✅  |  ✅  |  ❌  |  ❌  |
| house_of_fun                  |  ✅  |  ✅  |  ❌  |  ❌  |  ❌  |
| house_of_gods                 |  ✅  |  ❌  |  ❌  |  ❌  |  ❌  |
| tcache_poisoning              |  ❌  |  ✅  |  ✅  |  ✅  |  ✅  |
| tcache_house_of_spirit        |  ❌  |  ✅  |  ✅  |  ✅  |  ✅  |
| tcache_metadata_poisoning     |  ❌  |  ✅  |  ✅  |  ✅  |  ✅  |
| tcache_stashing_unlink_attack |  ❌  |  ✅  |  ✅  |  ✅  |  ✅  |
| fast_bin_reverse_into_tcache  |  ❌  |  ✅  |  ✅  |  ✅  |  ✅  |
| house_of_banana               |  ✅  |  ✅  |  ✅  |  ✅  |  ✅  |
| house_of_corrosion            |  ✅  |  ✅  |  ✅  |  ✅  |  ❌  |
| house_of_einherjar            |  ✅  |  ✅  |  ✅  |  ✅  |  ✅  |
| house_of_kiwi                 |  ✅  |  ✅  |  ✅  |  ✅  |  ❌  |
| house_of_husk                 |  ✅  |  ✅  |  ✅  |  ✅  |  ✅  |
| house_of_botcake              |  ❌  |  ✅  |  ✅  |  ✅  |  ✅  |
| house_of_io                   |  ❌  |  ❌  |  ✅  |  ✅  |  ✅  |
| house_of_tangerine            |  ❌  |  ✅  |  ✅  |  ❌  |  ❌  |
| house_of_apple_*              |  ✅  |  ✅  |  ✅  |  ✅  |  ✅  |
| house_of_emma*                |  ✅  |  ✅  |  ✅  |  ✅  |  ✅  |
| house_of_atum                 |  ❌  |  ✅  |  ❌  |  ❌  |  ❌  |
| house_of_snake                |  ❌  |  ❌  |  ❌  |  ❌  |  ✅  |
| house_of_mind_fastbin         |  ✅  |  ✅  |  ✅  |  ✅  |  ✅  |
| house_of_obstack              |  ✅  |  ✅  |  ✅  |  ✅  |  ❌  |
| sysmalloc_int_free            |  ✅  |  ✅  |  ✅  |  ✅  |  ✅  |

> ✅ — available in that glibc branch (including any numbered or suffixed variants). ❌ — not present.
> `*` — multiple variants, e.g. `house_of_apple_one` … `house_of_apple_eight`, `house_of_emma_one` … `house_of_emma_four`.
> `tcache_stashing_unlink_attack` covers `_again`, `_another`, and `tcache_stashing_unlink+_attack` on 2.35 / 2.39.

---

## Suggested Learning Path

1. **Foundations** — `unsorted_bin_leak`, `fast_bin_attack`, `unsafe_unlink`, `overlapping_chunks`, `poison_null_byte`.
2. **Bin attacks** — `large_bin_attack`, `unsorted_bin_attack`, `fast_bin_reverse_into_tcache`.
3. **House of series** — `house_of_spirit`, `house_of_lore`, `house_of_force`, `house_of_einherjar`, `house_of_kiwi`, `house_of_botcake`.
4. **tcache and modern glibc** — `tcache_poisoning`, `tcache_stashing_unlink_attack`, `tcache_metadata_poisoning`, `house_of_emma_*`, `house_of_snake`.
5. **Miscellaneous** — `sysmalloc_int_free`, `house_of_obstack`, `house_of_mind_fastbin`, and version-specific variants.

---

## Quick Start

### Prerequisites

- Linux host recommended
- Python 3
- Custom glibc toolchains installed under `/opt/glibc` (see [Prebuilt glibc Toolchain](#prebuilt-glibc-toolchain))
- An isolated environment for running the PoCs (container or VM)

### 1. Clone

```bash
git clone https://github.com/BinRacer/pwn4heap.git
cd pwn4heap
```

### 2. Install Python dependencies

Using `uv` (recommended):

```bash
uv sync
```

Or with `pip`:

```bash
pip install -r requirements.txt
```

### 3. Install system dependencies

```bash
sudo apt-get install gawk bison gcc-multilib g++-multilib -y
```

### 4. Run a technique

```bash
python src/2.39/house_of_apple_one/exploit.py
```

`exploit.py` resolves the repository root at runtime and links against the matching glibc under `/opt/glibc/<version>/amd64/`.

### 5. Rebuild the target (optional)

To rebuild the vulnerable binary against the shipped toolchain:

```bash
cd binary/2.39/09
make rebuild
cd -
python src/2.39/house_of_apple_one/exploit.py
```

To rebuild an entire glibc branch or the whole project:

```bash
cd binary/2.23     && make rebuild     # one version
cd binary          && make rebuild     # all versions
```

---

## Dependencies

- `pyproject.toml` — project metadata and Python dependencies.
- `requirements.txt` — flat dependency list for `pip` users.
- `uv.lock` — locked resolution for reproducible `uv sync`.

For more details on the layout and conventions, see [ProjectStructure.md](./ProjectStructure.md).

---

## Safety & Legal

- **Authorized use only** — test only systems you own or have explicit permission to test.
- **Isolated environments** — run labs in containers or VMs, never on production systems.
- **Educational purpose** — this repository is for learning and authorized security research.
- **No warranty** — the authors are not responsible for misuse or damage.

> Read the full [Disclaimer](./Disclaimer.md) before using this repository.

---

## License

This project is licensed under the **MIT License**. See [LICENSE](./LICENSE) for details.

---

<div align="center">
  <sub>Built with ❤️ for the security research community</sub>
</div>
