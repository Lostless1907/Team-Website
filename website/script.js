// Cool Matrix Effect
const canvas = document.getElementById("matrix");
const ctx = canvas.getContext("2d");

function resize() {
  canvas.width = window.innerWidth;
  canvas.height = window.innerHeight;
}
resize();
window.addEventListener("resize", resize);

const chars = "01Δ∇λΣΦΩABCDEFGHIJKLMNOPQRSTUVWXYZ";
const fontSize = 16;
const columns = Math.floor(canvas.width / fontSize);
const drops = Array(columns).fill(0);

function drawMatrix() {
  ctx.fillStyle = "rgba(2, 4, 20, 0.08)";
  ctx.fillRect(0, 0, canvas.width, canvas.height);

  ctx.fillStyle = "#2f9bff";
  ctx.font = `${fontSize}px monospace`;

  for (let i = 0; i < drops.length; i++) {
    const char = chars[Math.floor(Math.random() * chars.length)];
    ctx.fillText(char, i * fontSize, drops[i] * fontSize);

    if (drops[i] * fontSize > canvas.height && Math.random() > 0.98)
      drops[i] = 0;

    drops[i]++;
  }
}

setInterval(drawMatrix, 33);

// Term section
const typing = document.querySelector(".typing");
const text = "> computational environment online";
let idx = 0;

function type() {
  if (idx < text.length) {
    typing.textContent += text[idx++];
    setTimeout(type, 35);
  }
}
type();

