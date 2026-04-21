def rol(val, r):
    return ((val << r) | (val >> (8 - r))) & 0xFF

def encrypt(text):
    data = []

    for i, c in enumerate(text):
        b = ord(c)

        b ^= 0x5A
        b = rol(b, (i % 3) + 1)
        b = (b + i * 7) & 0xFF

        data.append(b)

    # reverse
    data = data[::-1]

    # 👉 zamiana na hex string
    return "".join(f"{b:02x}" for b in data)


if __name__ == "__main__":
    plaintext = "..."
    print(encrypt(plaintext))
