<?php
	$BookInfo = new SimpleXMLElement("<BookInfo/>");
	$book = $BookInfo->addChild("book");
	$book->addChild("bookNo","1");
	$book->addChild("bookName","Java");
	$book->addChild("authorName","Harshit");
	$book->addChild("price","250");
	$book->addChild("year","2006");
	$book = $BookInfo->addChild("book");
	$book->addChild("bookNo","2");
	$book->addChild("bookName","C");
	$book->addChild("authorName","Denis");
	$book->addChild("price","255");
	$book->addChild("year","2007");
	$BookInfo->asXML("setA3.xml");
?>
