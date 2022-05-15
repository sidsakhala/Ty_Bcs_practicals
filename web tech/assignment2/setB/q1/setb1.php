<?php
	$xml = simplexml_load_file("setb1.xml");
	foreach($xml as $book){
		echo"Book no".$book->bookNo."<br>";
		echo"Book name".$book->bookName."<br>";
		echo"Author Name".$book->authorName."<br>";
		echo"Price".$book->price."<br>";
		echo"Year".$book->year."<br>";

	}
?>
