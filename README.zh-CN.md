<div align="center">
  <a href="https://github.com/BinRacer/pwn4heap">
    <img src="images/banner.svg" alt="pwn4heap" style="width:100%; max-width:100%; margin-top:0; margin-bottom:-0.5rem">
  </a>

  <p>
    <a href="./README.md">English</a> | <a href="./README.zh-CN.md">简体中文</a>
  </p>

  <p>
    面向堆利用的实验项目——基于 Python PoC，覆盖 glibc 2.23 到 2.39。
  </p>

  <p>
    <a href="./LICENSE"><img src="https://img.shields.io/badge/License-MIT-blue.svg" alt="License: MIT"></a>
    <a href="#glibc-矩阵"><img src="https://img.shields.io/badge/glibc-2.23%20%7C%202.27%20%7C%202.31%20%7C%202.35%20%7C%202.39-informational" alt="glibc versions"></a>
  </p>
</div>

---

## 概述

`pwn4heap` 是对 **how2heap** 的 Python 重写。原项目用 C 片段展示每一项堆利用技术，本项目则将每项技术实现为独立的 Python PoC，便于阅读、修改，也更容易复用到真实目标上。

每项技术都配有对应的漏洞程序，基于特定 glibc 版本构建，并链接到安装在 `/opt/glibc` 下的自定义 glibc 工具链。

每个实验都独立可复现，通常包含以下内容：

- 漏洞程序及其源码，基于特定 glibc 版本构建；
- Python 利用 PoC；
- 提供 `rebuild` 目标的 `Makefile`；
- 各版本目录下的 `README.md`，列出该 glibc 分支的全部技术。

> 本项目仅用于授权安全研究与教学。详见 [Disclaimer](./Disclaimer.md)。

---

## 仓库结构

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
│   ├── Makefile              # 转发到 <version>/Makefile
│   └── <version>/            # 取值之一：2.23、2.27、2.31、2.35、2.39
│       ├── <NN>/             # 二进制目标；NN 在每个版本下单独计数（见下文）
│       └── Makefile          # 转发到 <NN>/Makefile
└── src/
    └── <version>/
        ├── <technique>/      # exploit.py + flag
        └── README.md         # 每个版本的技术索引
```

| 版本 | 二进制编号  | 技术亮点                                                                                                                                                            |
| ---- | ----------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 2.23 | `01` … `18` | tcache 之前：`house_of_*`、`unsorted_bin_*`、`large_bin_attack`、`fast_bin_attack`、`overlapping_chunks`、`poison_null_byte`、`sysmalloc_int_free`、`unsafe_unlink` |
| 2.27 | `01` … `21` | 新增 `tcache_*`、`fast_bin_reverse_into_tcache`、`house_of_atum`、`house_of_botcake`、`house_of_tangerine`、`sysmalloc_int_free_again`                              |
| 2.31 | `01` … `19` | 新增 `house_of_io`；扩展 `house_of_einherjar`、`house_of_lore`、`sysmalloc_int_free`、`tcache_stashing_unlink_attack`                                               |
| 2.35 | `01` … `11` | 新增 `house_of_emma_one` … `four`；移除仅适用于 tcache 之前的技术                                                                                                   |
| 2.39 | `01` … `09` | 新增 `house_of_snake`；引入最新的 tcache 与 large bin 缓解措施                                                                                                      |

> `*` 表示存在多个编号或后缀变体（例如 `house_of_apple_one` … `house_of_apple_eight`、`house_of_emma_one` … `house_of_emma_four`）。各分支的具体技术列表见对应 `src/<version>/README.md`。

---

## 实验结构

### 技术目录

每项技术位于 `src/<version>/` 下的独立目录中：

```text
<technique>/
├── exploit.py            # 对应技术的 Python PoC
└── flag                  # flag 文件（用于验证利用成功）
```

### 二进制目录

每个 glibc 版本还提供 `binary/` 目录，内含若干编号变体作为利用目标：

```text
binary/<version>/
├── 01/
│   ├── binary            # 编译好的漏洞程序
│   ├── binary.bndb       # Binary Ninja 数据库
│   ├── binary.c          # 源码
│   ├── ld-2.XX.so        # 匹配的动态链接器
│   ├── ld-linux-x86-64.so.2 -> ld-2.XX.so
│   ├── libc-2.XX.so      # 匹配的 libc
│   ├── libc.so.6 -> libc-2.XX.so
│   └── Makefile
├── 02/
├── ...
└── NN/
```

- 每个 `binary/<version>/NN/` 均自带可执行文件、源码以及对应的 `ld` 和 `libc`。
- 二进制已链接到 `/opt/glibc/<version>/amd64/`，安装好对应工具链后即可直接运行（见 [预构建 glibc 工具链](#预构建-glibc-工具链)）。
- Makefile 层级：
    - `binary/Makefile` 将 `all` / `clean` / `rebuild` / `help` 转发到各 `<version>/Makefile`；
    - `<version>/Makefile` 将同样的目标转发到各编号子目录；
    - `<version>/NN/Makefile` 基于 `/opt/glibc/<version>/amd64` 重新构建二进制。

---

## 预构建 glibc 工具链

本项目依赖安装在 `/opt/glibc` 下的自定义 glibc 构建。各版本的预编译包可从 [Releases](https://github.com/BinRacer/pwn4heap/releases) 页面下载：

| 版本 | 下载                                                                                                                 |
| ---- | -------------------------------------------------------------------------------------------------------------------- |
| 2.23 | [glibc-2.23_amd64.tar.xz](https://github.com/BinRacer/pwn4heap/releases/download/glibc_2.23/glibc-2.23_amd64.tar.xz) |
| 2.27 | [glibc-2.27_amd64.tar.xz](https://github.com/BinRacer/pwn4heap/releases/download/glibc_2.27/glibc-2.27_amd64.tar.xz) |
| 2.31 | [glibc-2.31_amd64.tar.xz](https://github.com/BinRacer/pwn4heap/releases/download/glibc_2.31/glibc-2.31_amd64.tar.xz) |
| 2.35 | [glibc-2.35_amd64.tar.xz](https://github.com/BinRacer/pwn4heap/releases/download/glibc_2.35/glibc-2.35_amd64.tar.xz) |
| 2.39 | [glibc-2.39_amd64.tar.xz](https://github.com/BinRacer/pwn4heap/releases/download/glibc_2.39/glibc-2.39_amd64.tar.xz) |

安装方式：

```bash
sudo mkdir -p /opt/glibc/
cd /opt/glibc
sudo tar -xJvf glibc-2.23_amd64.tar.xz
sudo tar -xJvf glibc-2.27_amd64.tar.xz
sudo tar -xJvf glibc-2.31_amd64.tar.xz
sudo tar -xJvf glibc-2.35_amd64.tar.xz
sudo tar -xJvf glibc-2.39_amd64.tar.xz
```

解压后，每个版本位于 `/opt/glibc/<version>/amd64/`，与随仓库提供的二进制和 Makefile 所期望的路径一致，无需额外配置。

---

## glibc 矩阵

技术按所针对的 glibc 版本分组。更新的 glibc 版本引入了新的缓解措施，也带来了新的技术。

| 分支 | 编号        | 重点                                                                        |
| ---- | ----------- | --------------------------------------------------------------------------- |
| 2.23 | `01` … `18` | tcache 之前：fastbin、unsorted bin、large bin、house of *、unsafe unlink 等 |
| 2.27 | `01` … `21` | 引入 tcache：tcache poisoning、tcache stashing unlink、tcache metadata      |
| 2.31 | `01` … `19` | tcache 与 safe-linking 的完善（house of botcake、house of io 等）           |
| 2.35 | `01` … `11` | 现代 tcache 加固；house of emma 系列；house of tangerine                    |
| 2.39 | `01` … `09` | 最新加固；house of snake；更新后的 tcache 与 large bin 变体                 |

> 仓库仅提供源码、Makefile 和预编译二进制。每个 `binary/<version>/NN/` 都包含运行目标所需的 `ld` 和 `libc`。

---

## 技术索引

每个 glibc 版本在自身目录下维护一份索引，列出该分支下的所有技术，并直接链接到对应的 `exploit.py`：

| 版本 | 索引                                       |
| ---- | ------------------------------------------ |
| 2.23 | [src/2.23/README.md](./src/2.23/README.md) |
| 2.27 | [src/2.27/README.md](./src/2.27/README.md) |
| 2.31 | [src/2.31/README.md](./src/2.31/README.md) |
| 2.35 | [src/2.35/README.md](./src/2.35/README.md) |
| 2.39 | [src/2.39/README.md](./src/2.39/README.md) |

下表汇总各 glibc 分支下可用的技术，大致按从易到难排列。

| 技术                          | 2.23 | 2.27 | 2.31 | 2.35 | 2.39 |
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

> ✅ — 该 glibc 分支下存在对应技术（含任意编号或后缀变体）。❌ — 不存在。
> `*` — 存在多个变体，例如 `house_of_apple_one` … `house_of_apple_eight`、`house_of_emma_one` … `house_of_emma_four`。
> `tcache_stashing_unlink_attack` 涵盖 `_again`、`_another`，以及 2.35 / 2.39 中的 `tcache_stashing_unlink+_attack`。

---

## 建议学习路径

1. **基础** — `unsorted_bin_leak`、`fast_bin_attack`、`unsafe_unlink`、`overlapping_chunks`、`poison_null_byte`。
2. **bin 攻击** — `large_bin_attack`、`unsorted_bin_attack`、`fast_bin_reverse_into_tcache`。
3. **house of 系列** — `house_of_spirit`、`house_of_lore`、`house_of_force`、`house_of_einherjar`、`house_of_kiwi`、`house_of_botcake`。
4. **tcache 与现代 glibc** — `tcache_poisoning`、`tcache_stashing_unlink_attack`、`tcache_metadata_poisoning`、`house_of_emma_*`、`house_of_snake`。
5. **杂项** — `sysmalloc_int_free`、`house_of_obstack`、`house_of_mind_fastbin`，以及各版本特有的变体。

---

## 快速开始

### 前置要求

- 推荐使用 Linux 主机
- Python 3
- 已在 `/opt/glibc` 下安装自定义 glibc 工具链（见 [预构建 glibc 工具链](#预构建-glibc-工具链)）
- 用于运行 PoC 的隔离环境（容器或虚拟机）

### 1. 克隆仓库

```bash
git clone https://github.com/BinRacer/pwn4heap.git
cd pwn4heap
```

### 2. 安装 Python 依赖

推荐使用 `uv`：

```bash
uv sync
```

或使用 `pip`：

```bash
pip install -r requirements.txt
```

### 3. 安装系统依赖

```bash
sudo apt-get install gawk bison gcc-multilib g++-multilib -y
```

### 4. 运行一项技术

```bash
python src/2.39/house_of_apple_one/exploit.py
```

`exploit.py` 会在运行时解析仓库根目录，并链接到 `/opt/glibc/<version>/amd64/` 下对应的 glibc。

### 5. 重新构建目标（可选）

如需基于随仓库提供的工具链重新构建漏洞程序：

```bash
cd binary/2.39/09
make rebuild
cd -
python src/2.39/house_of_apple_one/exploit.py
```

重建单个 glibc 分支或整个项目：

```bash
cd binary/2.23     && make rebuild     # 单个版本
cd binary          && make rebuild     # 全部版本
```

---

## 依赖

- `pyproject.toml` — 项目元数据与 Python 依赖。
- `requirements.txt` — 供 `pip` 使用的扁平化依赖列表。
- `uv.lock` — 锁定解析结果，便于可复现的 `uv sync`。

关于目录布局与约定的更多细节，请见 [ProjectStructure.md](./ProjectStructure.md)。

---

## 安全与法律

- **仅限授权使用** — 只测试你拥有或已获得明确书面许可的系统。
- **隔离环境** — 所有实验都在容器或虚拟机中进行，切勿在生产系统上运行。
- **教学目的** — 本仓库仅用于学习与授权安全研究。
- **不提供担保** — 作者不对任何误用或由此造成的损失负责。

> 使用前请先阅读完整的 [Disclaimer](./Disclaimer.md)。

---

## 许可证

本项目基于 **MIT** 许可证发布，详见 [LICENSE](./LICENSE)。
