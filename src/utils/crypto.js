function encrypt(input, key) {
  let output = "";

  for (let i = 0; i < input.length; i++) {
    const charCode =
      input.charCodeAt(i) ^
      key.charCodeAt(i % key.length) ^
      0x42;

    output += String.fromCharCode(charCode);
  }

  return output;
}

module.exports = { encrypt };