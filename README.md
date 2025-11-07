<div align="center">
  <!-- Banner with negative bottom margin -->
  <a href="https://github.com/BinRacer/pwn4heap">
    <img src="images/banner.svg" alt="pwn4heap" style="width:100%; max-width:100%; margin-top:0; margin-bottom:-0.5rem">
  </a>
</div>

---

## 📖 Overview

This repository is an enhanced and practical extension of the renowned **how2heap** tutorial.

While the original **how2heap** provides foundational examples of heap exploitation techniques in C, this project takes a significant step further by integrating production-ready Python Proof-of-Concept (PoC) exploits and modifying the original vulnerable programs to enable real-world getshell capabilities.

The primary goal is to bridge the gap between the oretical vulnerability demonstrations and practical exploitation. It moves beyond simple proof-of-concepts that might only demonstrate control flow hijacking or arbitrary writes, and focuses on achieving actual code execution in a realistic context. This involves adapting the original **how2heap** examples to create exploitable conditions that can lead to a shell, thereby providing a more hands-on and impactful learning experience for understanding heap vulnerabilities.

## 🛠️ Installation & Usage

### Prerequisites
- Python3
- GCC
- Make
- Authorized testing environment


### 🤔How To Use?

First, open Shell. And
👉 Run the following command:
```shell
git clone https://github.com/BinRacer/pwn4heap.git
cd pwn4heap
pip install -r requirements.txt
sudo apt-get install gawk bison gcc-multilib g++-multilib -y
```

The next step involves selecting a heap exploitation technique from within the src directory.
```shell
cd src/2.23/unsorted_bin_leak
# Synchronize and adjust the parameters in the Python file before rebuilding the binary.
# make rebuild
python exploit.py
```

## ⚠️ Global Legal Disclaimer for Security Research Software

**IMPORTANT: PLEASE READ THIS DISCLAIMER CAREFULLY BEFORE USING THIS SOFTWARE. THIS SOFTWARE IS INTENDED FOR AUTHORIZED SECURITY RESEARCH AND TESTING ONLY. UNAUTHORIZED USE IS STRICTLY PROHIBITED AND MAY RESULT IN SEVERE LEGAL CONSEQUENCES.**

### 1. Intended Use & Authorization Requirements

This exploit module is provided **solely for authorized security testing, educational purposes, and professional penetration testing** in environments where **explicit, written permission** has been obtained from all relevant rights holders. It is designed to help security professionals understand vulnerabilities, develop detection mechanisms, and improve defensive strategies.

**You must not use this module against any system, network, or device without prior explicit authorization from the owner.** Proper authorization must be obtained in writing and must clearly specify the scope, duration, and methods of testing.

### 2. Region-Specific Legal Considerations

#### 2.1 People's Republic of China
- Use of this software must comply with the **《中华人民共和国网络安全法》** (Cybersecurity Law of the PRC), **《中华人民共和国数据安全法》** (Data Security Law of the PRC), and **《中华人民共和国个人信息保护法》** (Personal Information Protection Law of the PRC).
- Unauthorized testing, especially that which accesses data or causes system damage, may be considered illegal under **《刑法》** (Criminal Law) Article 285, which prohibits unauthorized intrusion into computer information systems and illegal acquisition of computer information system data.
- According to judicial interpretations, obtaining 500+ sets of authentication information may be considered "serious circumstances" leading to criminal liability.
- Critical Information Infrastructure Operators require special authorization for testing.

#### 2.2 United States
- Unauthorized use may violate the **Computer Fraud and Abuse Act (CFAA)** (18 U.S.C. § 1030), which prohibits unauthorized access to computers and networks.
- State laws such as the **California Consumer Privacy Act (CCPA)** and emerging state privacy laws may impose additional restrictions and liabilities.
- Recent rules prohibit "covered" entities from certain countries from accessing sensitive U.S. personal data and government-related data, with exemptions for financial services, telecommunications, and healthcare compliance activities.

#### 2.3 European Union
- Compliance with the **General Data Protection Regulation (GDPR)** is required, particularly regarding any processing of personal data during testing activities.
- The **Network and Information Security (NIS) Directive** may impose additional security and notification requirements.
- GDPR Article 3 establishes extraterritorial application, meaning non-EU entities targeting EU residents may still be subject to GDPR requirements.

#### 2.4 Global Considerations
- Many countries have implemented similar laws restricting unauthorized access to computer systems and protecting data privacy.
- Some jurisdictions specifically regulate the possession and distribution of security testing tools.
- Data localization laws (e.g., China's requirement for important data to be stored domestically) may impact testing scenarios involving data processing or transfer.

### 3. Prohibition on Malicious Use

**Any use of this software without explicit authorization is strictly prohibited.** This includes but is not limited to:

- Testing on public networks or systems without ownership or authorization
- Testing on critical infrastructure without explicit permission
- Testing on systems located in jurisdictions where such testing is illegal
- Any use that violates applicable local, state, national, or international laws

### 4. Compliance Framework for Authorized Testing

When conducting authorized testing, ensure compliance with these principles:

- **Written Authorization**: Maintain documented permission from all relevant stakeholders
- **Scope Limitation**: Strictly adhere to the authorized scope of testing
- **Data Minimization**: Avoid unnecessary collection, processing, or storage of personal data
- **Boundary Respect**: Do not exceed the boundaries of authorized systems or networks
- **Reporting Obligations**: Follow responsible disclosure practices for discovered vulnerabilities

### 5. No Warranty & Limitation of Liability

This software is provided "**AS IS**" without any warranties, express or implied, including but not limited to the implied warranties of merchantability, fitness for a particular purpose, and non-infringement. The entire risk as to the quality and performance of the software is with you.

**In no event shall the authors, contributors, or copyright holders be liable for any direct, indirect, incidental, special, exemplary, or consequential damages** (including, but not limited to, procurement of substitute goods or services; loss of use, data, or profits; or business interruption) however caused and on any theory of liability, whether in contract, strict liability, or tort (including negligence or otherwise) arising in any way out of the use of this software, even if advised of the possibility of such damage.

### 6. User Responsibility

By using this software, **you assume full responsibility for any consequences** that may arise from its use. You are solely responsible for:

- Ensuring that your actions comply with all applicable local, state, national, and international laws and regulations
- Obtaining all necessary permissions and authorizations before use
- Ensuring that testing does not violate the rights of any third parties
- The ethical and legal use of this tool

The authors and contributors of this module disclaim all responsibility for any misuse or damage caused by this software.

### 7. Responsible Usage Guidelines

*   **Legal Authorization**: Always obtain **written permission** from the appropriate stakeholders before scanning, testing, or exploiting any system. Maintain documentation of this authorization.
*   **Controlled Environments**: Use this module only in **isolated lab environments** or controlled settings designed for security testing. **DO NOT run it against real-world production systems, public internet-facing systems, or any critical infrastructure without explicit, written authorization.**
*   **Ethical Conduct**: Use your skills ethically and responsibly. The discovery of vulnerabilities should be reported to the vendor through coordinated vulnerability disclosure (CVD) processes.
*   **Education and Awareness**: This tool is meant to deepen understanding of exploit development and defense. Use it to promote learning and improve security postures.
*   **Data Protection**: When testing involves personal data, implement appropriate safeguards including encryption, access controls, and data minimization techniques.

### 8. Regional Representation Requirements

Depending on your location and target, you may need to appoint local representatives:

- **EU**: GDPR Article 27 requires non-EU entities subject to GDPR to designate a representative in the EU.
- **China**: The Personal Information Protection Law may require foreign entities to establish dedicated entities or appoint representatives within China for data protection matters.

### 9. Testing Considerations

If you have a vulnerable setup for testing, you can specify the target details here. **Never test on unauthorized systems.**

When testing, consider these jurisdictional issues:

- **Data Sovereignty**: Be aware of data localization requirements that may restrict cross-border data transfers during testing.
- **Extraterritorial Laws**: Some laws (e.g., GDPR, U.S. Cloud Act) have extraterritorial application.
- **Conflicting Requirements**: Different jurisdictions may have conflicting requirements, particularly regarding data access and transfer.

### 10. License

This Metasploit module is licensed under the **MIT License**. See the `LICENSE` file for details.

---

**By using this software, you acknowledge that you have read this disclaimer, understand it, and agree to be bound by its terms. You confirm that you will use this software only in compliance with all applicable laws and regulations and with proper authorization.**
