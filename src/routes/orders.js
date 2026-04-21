const express = require("express");
const router = express.Router();

const orders = [
  { id: 1, item: "latte" },
  { id: 2, item: "cappuccino" },
  { id: 3, item: "flat_white" }
];

router.get("/", (req, res) => {
  res.json(orders);
});

module.exports = router;