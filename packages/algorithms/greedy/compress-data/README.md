# 🗜️ Data Compression

Data Compression is a **combinatorial optimization problem** — representing data in a way that occupies the least possible storage space. Specifically, it focuses on optimal prefix encoding: given a set of characters and their frequencies, build a binary code such that no code is a prefix of another (**prefix-free**) and the total weighted code length is minimized.

This is a **Greedy problem** — the greedy choice at each step (always merging the two nodes with the smallest frequency) is mathematically proven to always yield a globally optimal result, without needing backtracking or dynamic programming.

---

## 📂 List of Algorithms

| # | Algorithm | Status |
|---|-----------|--------|
| 1 | [Run-Length Encoding (RLE)](#1-run-length-encoding-rle) | ⬜ |
| 2 | [Huffman Coding](#2-huffman-coding) | ✅ |
| 3 | [LZ77 / LZ78](#3-lz77--lz78) | ⬜ |
| 4 | [Arithmetic Coding (AC)](#4-arithmetic-coding-ac) | ⬜ |

---

## Core Concepts

### Lossless vs Lossy Compression

| Type | Description | Use Cases |
|------|-------------|-----------|
| **Lossless** | Decompressed data is **exactly identical** to the original | Text, source code, system files — where absolute accuracy is required |
| **Lossy** | Accepts losing some non-critical data | Images, video, audio — where the human eye/ear cannot detect minor differences |

> All algorithms in this folder are **lossless** compression techniques.

### Prefix-Free Code
A set of binary codes where **no code is a prefix of another**. This ensures unambiguous decoding without needing separators. Huffman Coding is the classic example.

### Entropy
The theoretical **lower bound** on the average number of bits needed to encode a symbol, based on its probability. A compression algorithm is optimal when its average code length approaches the entropy of the source.

---

## 1. Run-Length Encoding (RLE)

### Description
Replaces consecutive repeated characters with a **count and the character**. For example, `AAABBBCC` becomes `3A3B2C`. Simple and fast, but only effective when data contains long runs of repeated values.

### When to use
- Data with **long sequences of repeated values** (e.g., simple bitmap images, fax transmission).
- As a preprocessing step before more advanced compression.

### Complexity
| | Time | Space |
|--|------|-------|
| **Complexity** | O(n) | O(n) |

> ⬜ **Not yet implemented** — will be updated later.

---

## 2. Huffman Coding

### Description
Builds an optimal **prefix-free binary tree** by greedily merging the two least-frequent symbols at each step. More frequent characters receive shorter codes, less frequent ones receive longer codes — minimizing the total encoded length.

**Steps:**
1. Count the frequency of each character.
2. Insert all characters into a **min-heap** ordered by frequency.
3. Repeatedly extract the two minimum nodes, merge them into a new node with combined frequency, and reinsert.
4. The resulting tree defines the optimal prefix-free code for each character.

### When to use
- **Text and file compression** (used in ZIP, GZIP, JPEG, MP3).
- When character frequencies are known in advance (static Huffman).
- As a component of more complex compression pipelines.

### Complexity
| | Time | Space |
|--|------|-------|
| **Complexity** | O(n log n) | O(n) |

---

## 3. LZ77 / LZ78

### Description
Dictionary-based compression algorithms that replace repeated sequences with **references to earlier occurrences** in the data stream.
- **LZ77** uses a sliding window to find matches in recent data.
- **LZ78** builds an explicit dictionary of seen patterns incrementally.

These algorithms form the basis of many modern formats (ZIP, GZIP, PNG).

### When to use
- **General-purpose compression** of text and binary files.
- When patterns and repeated sequences appear throughout the data.

### Complexity
| | Time | Space |
|--|------|-------|
| **LZ77** | O(n²) naive / O(n) optimized | O(window size) |
| **LZ78** | O(n) | O(dictionary size) |

> ⬜ **Not yet implemented** — will be updated later.

---

## 4. Arithmetic Coding (AC)

### Description
Encodes an entire message as a **single fraction** in the range [0, 1). Each symbol narrows the interval according to its probability. Achieves compression closer to the theoretical entropy limit than Huffman Coding, but is more computationally expensive.

### When to use
- When **maximum compression ratio** is required.
- Used in high-performance formats like JPEG 2000 and HEVC video.
- When symbol probabilities are known and can be modeled accurately.

### Complexity
| | Time | Space |
|--|------|-------|
| **Complexity** | O(n) | O(1) |

> ⬜ **Not yet implemented** — will be updated later.

---

## 📊 Algorithm Comparison

| Algorithm | Type | Compression Ratio | Speed | Use Case |
|-----------|------|------------------|-------|----------|
| RLE | Lossless | Low (data-dependent) | Very fast | Repeated-value data |
| Huffman Coding | Lossless | Good | Fast | General text / files |
| LZ77 / LZ78 | Lossless | Very good | Moderate | General-purpose files |
| Arithmetic Coding | Lossless | Near-optimal | Slow | Maximum compression |

---

## 🧭 When to Use Which Algorithm?

| Situation | Recommended Algorithm |
|-----------|----------------------|
| Simple repeated data (bitmaps, fax) | RLE |
| General text, known frequencies | Huffman Coding |
| General-purpose files, repeated patterns | LZ77 / LZ78 |
| Maximum compression, complex models | Arithmetic Coding |