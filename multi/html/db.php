<html>
<body>
<?php
$servername = "romulus";
$username = "moo";
$password = "potato";

// Create connection
$conn = new mysqli($servername, $username, $password, "food");

// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}
echo "Connected successfully <br>";

$sql = "SELECT name FROM fruit";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
  // output data of each row
  while($row = $result->fetch_assoc()) {
    echo "Name: " . $row["name"] . "<br>";
  }
} else {
  echo "0 results";
}
$conn->close();

?>
</body>
</html>
