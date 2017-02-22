#include "EmeraldMod.h"

#include "minecraftpe/world/level/block/FenceBlock.h"
#include "minecraftpe/world/level/block/SlabBlock.h"
#include "minecraftpe/world/level/block/TorchBlock.h"
#include "minecraftpe/world/level/block/LadderBlock.h"
#include "blocks/EmeraldMushroomBlock.h"

#include "items/EmeraldArmor.h"
#include "items/SwordItem.h"
#include "items/SuperSwordItem.h"
#include "items/PickaxeItem.h"
#include "items/AxeItem.h"
#include "items/PaxItem.h"
#include "items/ShovelItem.h"
#include "items/HoeItem.h"
#include "items/FlintAndEmerald.h"
#include "items/EmeraldBowItem.h"

Item* EmeraldMod::mHelmet;
Item* EmeraldMod::mChestplate;
Item* EmeraldMod::mLeggings;
Item* EmeraldMod::mBoots;
Item* EmeraldMod::mSword;
Item* EmeraldMod::mSuperSword;
Item* EmeraldMod::mPickaxe;
Item* EmeraldMod::mAxe;
Item* EmeraldMod::mShovel;
Item* EmeraldMod::mHoe;
Item* EmeraldMod::mPax;
Item* EmeraldMod::mFlintAndEmerald;
Item* EmeraldMod::mBow;
Item* EmeraldMod::mStick;
Item* EmeraldMod::mNugget;

Block* EmeraldMod::mPlanks;
Block* EmeraldMod::mBrick;
Block* EmeraldMod::mFence;
Block* EmeraldMod::mSlab;
Block* EmeraldMod::mTorch;
Block* EmeraldMod::mLadder;
Block* EmeraldMod::mMushroom;

void EmeraldMod::initItems()
{
	mHelmet = new EmeraldHelmet(3800);
	mChestplate = new EmeraldChestplate(3801);
	mLeggings = new EmeraldLeggings(3802);
	mBoots = new EmeraldBoots(3803);
	mSword = new SwordItem(3804);
	mSuperSword = new SuperSwordItem(3805);
	mPickaxe = new PickaxeItem(3806);
	mAxe = new AxeItem(3807);
	mPax = new PaxItem(3808);
	mShovel = new ShovelItem(3809);
	mHoe = new HoeItem(3810);
	mFlintAndEmerald = new FlintAndEmerald(3811);
	//mBow = new EmeraldBowItem(3812);
	Item::mItems[3813] = mStick = (new Item("emeraldStick", 3813 - 256))->setIcon("emerald_stick", 0);
	Item::mItems[3814] = mNugget = (new Item("emeraldNugget", 3814 - 256))->setIcon("emerald_nugget", 0);
}

void EmeraldMod::initBlocks()
{
	Block::mBlocks[232] = mPlanks = new Block("emeraldPlanks", 232, Material::getMaterial(MaterialType::WOOD));
	mPlanks->setCategory(CreativeItemCategory::Blocks);
	mPlanks->setDestroyTime(1.4f);
	mPlanks->setExplodeable(5.0f);
	
	Block::mBlocks[233] = mBrick = new Block("emeraldBrick", 233, Material::getMaterial(MaterialType::STONE));
	mBrick->setCategory(CreativeItemCategory::Blocks);
	mBrick->setDestroyTime(2.0f);
	mBrick->setExplodeable(8.0f);
	
	Block::mBlocks[234] = mFence = new FenceBlock("emeraldFence", 234, Material::getMaterial(MaterialType::METAL));
	mFence->setSolid(false);
	mFence->setCategory(CreativeItemCategory::Decorations);
	mFence->setDestroyTime(2.0f);
	mFence->setExplodeable(8.0f);
	
	Block::mBlocks[235] = mSlab = new SlabBlock("emeraldSlab", 235, false, Material::getMaterial(MaterialType::METAL));
	mSlab->setCategory(CreativeItemCategory::Blocks);
	mSlab->setDestroyTime(2.2f);
	mSlab->setExplodeable(8.0f);
	
	mMushroom = new EmeraldMushroomBlock(236);
	
	//Block::mBlocks[236] = mTorch = new TorchBlock("emeraldTorch", 236);
	//mTorch->setCategory(CreativeItemCategory::Tools);
	
	//Block::mBlocks[237] = mLadder = new LadderBlock("emeraldLadder", 237);
	//mLadder->setCategory(CreativeItemCategory::Decorations);
}

void EmeraldMod::initBlockItems()
{
	Item::mItems[232] = new BlockItem(mPlanks->getDescriptionId(), 232 - 256);
	Item::mItems[233] = new BlockItem(mBrick->getDescriptionId(), 233 - 256);
	Item::mItems[234] = new BlockItem(mFence->getDescriptionId(), 234 - 256);
	Item::mItems[235] = new BlockItem(mSlab->getDescriptionId(), 235 - 256);
	Item::mItems[236] = new BlockItem(mMushroom->getDescriptionId(), 236 - 256);
}

void EmeraldMod::initBlockGraphics()
{
	BlockGraphics::mBlocks[232] = new BlockGraphics("dirt");
	BlockGraphics::mBlocks[232]->setTextureItem("emerald_planks");
	BlockGraphics::mBlocks[232]->setSoundType(BlockSoundType::WOOD);
	
	BlockGraphics::mBlocks[233] = new BlockGraphics("dirt");
	BlockGraphics::mBlocks[233]->setTextureItem("emerald_brick");
	
	BlockGraphics::mBlocks[234] = new BlockGraphics("dirt");
	BlockGraphics::mBlocks[234]->setTextureItem("emerald_block");
	BlockGraphics::mBlocks[234]->setBlockShape(BlockShape::FENCE);
	
	BlockGraphics::mBlocks[235] = new BlockGraphics("dirt");
	BlockGraphics::mBlocks[235]->setTextureItem("emerald_block");
	BlockGraphics::mBlocks[235]->setSoundType(BlockSoundType::METAL);
	
	BlockGraphics::mBlocks[236] = new BlockGraphics("sapling");
	BlockGraphics::mBlocks[236]->setTextureItem("emerald_mushroom");
	BlockGraphics::mBlocks[236]->setBlockShape(BlockShape::CROSS_TEXTURE);
	
	//BlockGraphics::mBlocks[236] = new BlockGraphics("torch");
	//BlockGraphics::mBlocks[236]->setTextureItem("emerald_torch");
	//BlockGraphics::mBlocks[236]->setBlockShape(BlockShape::TORCH);
	
	//BlockGraphics::mBlocks[237] = new BlockGraphics("ladder");
	//BlockGraphics::mBlocks[237]->setTextureItem("emerald_ladder");
	//BlockGraphics::mBlocks[237]->setSoundType(BlockSoundType::LADDER);
	//BlockGraphics::mBlocks[237]->setBlockShape(BlockShape::LADDER);
}

void EmeraldMod::initCreativeItems()
{
	Item::addCreativeItem(3800, 0);
	Item::addCreativeItem(3801, 0);
	Item::addCreativeItem(3802, 0);
	Item::addCreativeItem(3803, 0);
	Item::addCreativeItem(3804, 0);
	Item::addCreativeItem(3805, 0);
	Item::addCreativeItem(3806, 0);
	Item::addCreativeItem(3807, 0);
	Item::addCreativeItem(3808, 0);
	Item::addCreativeItem(3809, 0);
	Item::addCreativeItem(3810, 0);
	Item::addCreativeItem(3811, 0);
	//Item::addCreativeItem(3812, 0);
	Item::addCreativeItem(3813, 0);
	Item::addCreativeItem(3814, 0);
}

void EmeraldMod::initCreativeBlocks()
{
	Item::addCreativeItem(232, 0);
	Item::addCreativeItem(233, 0);
	Item::addCreativeItem(234, 0);
	Item::addCreativeItem(235, 0);
	Item::addCreativeItem(236, 0);
}

