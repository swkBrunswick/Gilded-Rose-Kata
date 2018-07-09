#include <gtest/gtest.h>

#include "GildedRose.h"
GildedRose example();

TEST(GildedRoseTest, Foo) {
    vector<Item> items;
    items.push_back(Item("Foo", 0, 0));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ("Foo", app.items[0].name);
}

TEST(GildedRoseTest, sellInAndQualityAreLoweredEveryDay) {
	GildedRose app = example();
	static const map<string, int> expectedQualities = {
			{"+5 Dexterity Vest", 19},
			{"Aged Brie", 1},
			{"Elixir of the Mongoose", 6},
			{"Sulfuras, Hand of Ragnaros", 80},
			{"Backstage passes to a TAFKAL80ETC concert", 21},
			{"Conjured Mana Cake", 4}};

	for (const Item &curItem : app.items)
		EXPECT_EQ(curItem.quality, expectedQualities.at(curItem.name));

}


GildedRose example()
{
    vector<Item> items;
    items.push_back(Item("+5 Dexterity Vest", 10, 20));
    items.push_back(Item("Aged Brie", 2, 0));
    items.push_back(Item("Elixir of the Mongoose", 5, 7));
    items.push_back(Item("Sulfuras, Hand of Ragnaros", 0, 80));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 15, 20));
    items.push_back(Item("Conjured Mana Cake", 3, 6));
    GildedRose app(items);
    app.updateQuality();
    return app;

}
