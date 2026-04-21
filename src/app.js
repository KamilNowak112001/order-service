const express = require("express");
const orders = require("./routes/orders");

const app = express();

app.use(express.json());

app.use("/orders", orders);

app.get("/", (req, res) => {
  res.send("Order service running");
});

// debug endpoint (should not be public)
app.get("/debug", (req, res) => {
  res.json({
    status: "debug active",
    note: "remove before prod"
  });
});

app.listen(3000, () => {
  console.log("Server started on port 3000");
});