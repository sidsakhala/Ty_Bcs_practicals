<?php
	$ItemInfo = new SimpleXMLElement("<ItemInfo/>");
	$Item = $ItemInfo->addChild("Item");
	$Item->addChild("ItemName","Cookies");
	$Item->addChild("ItemPrice","500");
	$Item->addChild("Quantity","25");
	$Item = $ItemInfo->addChild("Item");
	$Item->addChild("ItemName","Cakes");
	$Item->addChild("ItemPrice","300");
	$Item->addChild("Quantity","20");
	$Item = $ItemInfo->addChild("Item");
	$Item->addChild("ItemName","Puff");
	$Item->addChild("ItemPrice","100");
	$Item->addChild("Quantity","30");
	$Item = $ItemInfo->addChild("Item");
	$Item->addChild("ItemName","Donut");
	$Item->addChild("ItemPrice","250");
	$Item->addChild("Quantity","20");
	$Item = $ItemInfo->addChild("Item");
	$Item->addChild("ItemName","Rolls");
	$Item->addChild("ItemPrice","200");
	$Item->addChild("Quantity","250");
	$ItemInfo->asXML("setA1a.xml");

?>
