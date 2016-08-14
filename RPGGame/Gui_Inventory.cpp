#include "SDL/include/SDL.h"
#include "GUI.h"
#include "GUI_Inventory.h"
#include "GUI_Characters.h"
#include "ModuleCollider.h"
#include "ModuleTexture.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleCollider.h"
GUI_Inventory::GUI_Inventory()
{

}
GUI_Inventory::~GUI_Inventory()
{}

bool GUI_Inventory::Start()
{
	Inventory = App->texture->Load("Inventory.png");
	InventoryIs = OFF;
	InventoryCharacter = NO_CHARACTER;
	Player1 = { 600, 10, 80, 80 };
	Player2 = { 600, 110, 80, 80 };
	Player3 = { 600, 210, 80, 80 };
	Player4 = { 600, 310, 80, 80 };
	Exit = { 499, 3, 13, 13 };
	Arrow_left = { 516, 135, 30, 30 };
	Arrow_right = { 555, 135, 30, 30 };
	Inventory_background = { 0, 0, 306, 401 };
	bool ret = true;
	LOG("Loading frontground assets");
	return ret;
}

bool GUI_Inventory::CleanUp()
{

	App->texture->Unload(Inventory);

	LOG("Unloading Common Levels stuff");
	return true;
}
void GUI_Inventory::Retexture(){
	if (InventoryIs != OFF){
		App->render->Blit(Inventory, 490 * SCREEN_SIZE, 0 * SCREEN_SIZE, &Inventory_background);
		switch (InventoryCharacter)
		{
		//617 220
		case CHARACTER_ONE:
			//Character Icon
			if (App->gui_character->character[CHARACTER_ONE]->CurrentState == ALIVE)
				App->render->Blit(App->gui_character->Characters_sprites, 500 * SCREEN_SIZE, 0, &App->gui_character->character[CHARACTER_ONE]->Character_alive);
			else if (App->gui_character->character[0]->CurrentState == INJURED)
				App->render->Blit(App->gui_character->Characters_sprites, 500 * SCREEN_SIZE, 0, &App->gui_character->character[CHARACTER_ONE]->Character_injured);
			else
				App->render->Blit(App->gui_character->Characters_sprites, 500 * SCREEN_SIZE, 0, &App->gui_character->character[CHARACTER_ONE]->Character_dead);
			//Life/Mana Bar
			App->render->Blit(App->gui_character->Characters_sprites, 498 * SCREEN_SIZE, 97 * SCREEN_SIZE, &App->gui_character->character[CHARACTER_ONE]->Character_life);
			App->render->Blit(App->gui_character->Characters_sprites, 498 * SCREEN_SIZE, 115 * SCREEN_SIZE, &App->gui_character->character[CHARACTER_ONE]->Character_mana);
			//ITEMS
			if (!App->player->formation[CHARACTER_ONE]->inventory.Empty()){
				DoubleList<Item*>::nodeD* item = App->player->formation[CHARACTER_ONE]->inventory.first_node;
				for (; item != nullptr; item = item->next){
					if (item->data->itemSlot > 8){
						if (item->data->itemSlot == 9){
							App->render->Blit(App->items->itemssprite, 739  * SCREEN_SIZE, 16 * SCREEN_SIZE, &item->data->sprite);
							if (item->data->isSelected == true)
								App->render->Blit(App->items->itemssprite, 739 * SCREEN_SIZE, 16 * SCREEN_SIZE, &App->items->spriteSelected);
							
						}
						else if (item->data->itemSlot == 10){
							App->render->Blit(App->items->itemssprite, 739 * SCREEN_SIZE, 82 * SCREEN_SIZE, &item->data->sprite);
							if (item->data->isSelected == true)
								App->render->Blit(App->items->itemssprite, 739 * SCREEN_SIZE, 82 * SCREEN_SIZE, &App->items->spriteSelected);
						}
						else if (item->data->itemSlot == 11){
							App->render->Blit(App->items->itemssprite, 739 * SCREEN_SIZE, 148 * SCREEN_SIZE, &item->data->sprite);
							if (item->data->isSelected == true)
								App->render->Blit(App->items->itemssprite, 739 * SCREEN_SIZE, 148 * SCREEN_SIZE, &App->items->spriteSelected);
						}
					}
					else{
						for (int i = 0; i < MAX_COLUMNS; i++){
							for (int j = 0; j < MAX_ROWS; j++){
								if ((j*MAX_COLUMNS) + i == item->data->itemSlot){
									App->render->Blit(App->items->itemssprite, 613 + (i * 58) * SCREEN_SIZE, 220+(j * 58) * SCREEN_SIZE, &item->data->sprite);
									if (item->data->isSelected == true){
										App->render->Blit(App->items->itemssprite, 613 + (i * 58) * SCREEN_SIZE, 220 + (j * 58) * SCREEN_SIZE, &App->items->spriteSelected);
									}
								}
							}
						}
					}
				}
				
			}
			break;

		case CHARACTER_TWO:
			//Character Icon
			if (App->gui_character->character[CHARACTER_TWO]->CurrentState == ALIVE)
				App->render->Blit(App->gui_character->Characters_sprites, 500 * SCREEN_SIZE, 0, &App->gui_character->character[CHARACTER_TWO]->Character_alive);
			else if (App->gui_character->character[CHARACTER_TWO]->CurrentState == INJURED)
				App->render->Blit(App->gui_character->Characters_sprites, 500 * SCREEN_SIZE, 0, &App->gui_character->character[CHARACTER_TWO]->Character_injured);
			else
				App->render->Blit(App->gui_character->Characters_sprites, 500 * SCREEN_SIZE, 0, &App->gui_character->character[CHARACTER_TWO]->Character_dead);
			//Life/Mana Bar
			App->render->Blit(App->gui_character->Characters_sprites, 498 * SCREEN_SIZE, 97 * SCREEN_SIZE, &App->gui_character->character[CHARACTER_TWO]->Character_life);
			App->render->Blit(App->gui_character->Characters_sprites, 498 * SCREEN_SIZE, 115 * SCREEN_SIZE, &App->gui_character->character[CHARACTER_TWO]->Character_mana);
			//ITEMS
			if (!App->player->formation[CHARACTER_TWO]->inventory.Empty()){
				DoubleList<Item*>::nodeD* item = App->player->formation[CHARACTER_TWO]->inventory.first_node;
				for (; item != nullptr; item = item->next){
					if (item->data->itemSlot > 8){
						if (item->data->itemSlot == 9){
							App->render->Blit(App->items->itemssprite, 739 * SCREEN_SIZE, 16 * SCREEN_SIZE, &item->data->sprite);
							if (item->data->isSelected == true)
								App->render->Blit(App->items->itemssprite, 739 * SCREEN_SIZE, 16 * SCREEN_SIZE, &App->items->spriteSelected);

						}
						else if (item->data->itemSlot == 10){
							App->render->Blit(App->items->itemssprite, 739 * SCREEN_SIZE, 82 * SCREEN_SIZE, &item->data->sprite);
							if (item->data->isSelected == true)
								App->render->Blit(App->items->itemssprite, 739 * SCREEN_SIZE, 82 * SCREEN_SIZE, &App->items->spriteSelected);
						}
						else if (item->data->itemSlot == 11){
							App->render->Blit(App->items->itemssprite, 739 * SCREEN_SIZE, 148 * SCREEN_SIZE, &item->data->sprite);
							if (item->data->isSelected == true)
								App->render->Blit(App->items->itemssprite, 739 * SCREEN_SIZE, 148 * SCREEN_SIZE, &App->items->spriteSelected);
						}
					}
					else{
						for (int i = 0; i < MAX_COLUMNS; i++){
							for (int j = 0; j < MAX_ROWS; j++){
								if ((j*MAX_COLUMNS) + i == item->data->itemSlot){
									App->render->Blit(App->items->itemssprite, 613 + (i * 58) * SCREEN_SIZE, 220 + (j * 58) * SCREEN_SIZE, &item->data->sprite);
									if (item->data->isSelected == true){
										App->render->Blit(App->items->itemssprite, 613 + (i * 58) * SCREEN_SIZE, 220 + (j * 58) * SCREEN_SIZE, &App->items->spriteSelected);
									}
								}
							}
						}
					}
				}

			}
			break;

		case CHARACTER_THREE:
			//Character Icon
			if (App->gui_character->character[CHARACTER_THREE]->CurrentState == ALIVE)
				App->render->Blit(App->gui_character->Characters_sprites, 500 * SCREEN_SIZE, 0, &App->gui_character->character[CHARACTER_THREE]->Character_alive);
			else if (App->gui_character->character[CHARACTER_THREE]->CurrentState == INJURED)
				App->render->Blit(App->gui_character->Characters_sprites, 500 * SCREEN_SIZE, 0, &App->gui_character->character[CHARACTER_THREE]->Character_injured);
			else
				App->render->Blit(App->gui_character->Characters_sprites, 500 * SCREEN_SIZE, 0, &App->gui_character->character[CHARACTER_THREE]->Character_dead);
			//Life/Mana Bar
			App->render->Blit(App->gui_character->Characters_sprites, 498 * SCREEN_SIZE, 97 * SCREEN_SIZE, &App->gui_character->character[CHARACTER_THREE]->Character_life);
			App->render->Blit(App->gui_character->Characters_sprites, 498 * SCREEN_SIZE, 115 * SCREEN_SIZE, &App->gui_character->character[CHARACTER_THREE]->Character_mana);
			//ITEMS
			if (!App->player->formation[CHARACTER_THREE]->inventory.Empty()){
				DoubleList<Item*>::nodeD* item = App->player->formation[CHARACTER_THREE]->inventory.first_node;
				for (; item != nullptr; item = item->next){
					if (item->data->itemSlot > 8){
						if (item->data->itemSlot == 9){
							App->render->Blit(App->items->itemssprite, 739 * SCREEN_SIZE, 16 * SCREEN_SIZE, &item->data->sprite);
							if (item->data->isSelected == true)
								App->render->Blit(App->items->itemssprite, 739 * SCREEN_SIZE, 16 * SCREEN_SIZE, &App->items->spriteSelected);

						}
						else if (item->data->itemSlot == 10){
							App->render->Blit(App->items->itemssprite, 739 * SCREEN_SIZE, 82 * SCREEN_SIZE, &item->data->sprite);
							if (item->data->isSelected == true)
								App->render->Blit(App->items->itemssprite, 739 * SCREEN_SIZE, 82 * SCREEN_SIZE, &App->items->spriteSelected);
						}
						else if (item->data->itemSlot == 11){
							App->render->Blit(App->items->itemssprite, 739 * SCREEN_SIZE, 148 * SCREEN_SIZE, &item->data->sprite);
							if (item->data->isSelected == true)
								App->render->Blit(App->items->itemssprite, 739 * SCREEN_SIZE, 148 * SCREEN_SIZE, &App->items->spriteSelected);
						}
					}
					else{
						for (int i = 0; i < MAX_COLUMNS; i++){
							for (int j = 0; j < MAX_ROWS; j++){
								if ((j*MAX_COLUMNS) + i == item->data->itemSlot){
									App->render->Blit(App->items->itemssprite, 613 + (i * 58) * SCREEN_SIZE, 220 + (j * 58) * SCREEN_SIZE, &item->data->sprite);
									if (item->data->isSelected == true){
										App->render->Blit(App->items->itemssprite, 613 + (i * 58) * SCREEN_SIZE, 220 + (j * 58) * SCREEN_SIZE, &App->items->spriteSelected);

									}
								}
								
							}
						}
					}
				}

			}
			break;

		case CHARACTER_FOUR:
			//Character Icon
			if (App->gui_character->character[CHARACTER_FOUR]->CurrentState == ALIVE)
				App->render->Blit(App->gui_character->Characters_sprites, 500 * SCREEN_SIZE, 0, &App->gui_character->character[CHARACTER_FOUR]->Character_alive);
			else if (App->gui_character->character[CHARACTER_FOUR]->CurrentState == INJURED)
				App->render->Blit(App->gui_character->Characters_sprites, 500 * SCREEN_SIZE, 0, &App->gui_character->character[CHARACTER_FOUR]->Character_injured);
			else
				App->render->Blit(App->gui_character->Characters_sprites, 500 * SCREEN_SIZE, 0, &App->gui_character->character[CHARACTER_FOUR]->Character_dead);
			//Life/Mana Bar
			App->render->Blit(App->gui_character->Characters_sprites, 498 * SCREEN_SIZE, 97 * SCREEN_SIZE, &App->gui_character->character[CHARACTER_FOUR]->Character_life);
			App->render->Blit(App->gui_character->Characters_sprites, 498 * SCREEN_SIZE, 115 * SCREEN_SIZE, &App->gui_character->character[CHARACTER_FOUR]->Character_mana);
			//ITEMS
			if (!App->player->formation[CHARACTER_FOUR]->inventory.Empty()){
				DoubleList<Item*>::nodeD* item = App->player->formation[CHARACTER_FOUR]->inventory.first_node;
				for (; item != nullptr; item = item->next){
					if (item->data->itemSlot > 8){
						if (item->data->itemSlot == 9){
							App->render->Blit(App->items->itemssprite, 739 * SCREEN_SIZE, 16 * SCREEN_SIZE, &item->data->sprite);
							if (item->data->isSelected == true)
								App->render->Blit(App->items->itemssprite, 739 * SCREEN_SIZE, 16 * SCREEN_SIZE, &App->items->spriteSelected);

						}
						else if (item->data->itemSlot == 10){
							App->render->Blit(App->items->itemssprite, 739 * SCREEN_SIZE, 82 * SCREEN_SIZE, &item->data->sprite);
							if (item->data->isSelected == true)
								App->render->Blit(App->items->itemssprite, 739 * SCREEN_SIZE, 82 * SCREEN_SIZE, &App->items->spriteSelected);
						}
						else if (item->data->itemSlot == 11){
							App->render->Blit(App->items->itemssprite, 739 * SCREEN_SIZE, 148 * SCREEN_SIZE, &item->data->sprite);
							if (item->data->isSelected == true)
								App->render->Blit(App->items->itemssprite, 739 * SCREEN_SIZE, 148 * SCREEN_SIZE, &App->items->spriteSelected);
						}
					}
					else{
						for (int i = 0; i < MAX_COLUMNS; i++){
							for (int j = 0; j < MAX_ROWS; j++){
								if ((j*MAX_COLUMNS) + i == item->data->itemSlot){
									App->render->Blit(App->items->itemssprite, 613 + (i * 58) * SCREEN_SIZE, 220 + (j * 58) * SCREEN_SIZE, &item->data->sprite);
									if (item->data->isSelected == true){
										App->render->Blit(App->items->itemssprite, 613 + (i * 58) * SCREEN_SIZE, 220 + (j * 58) * SCREEN_SIZE, &App->items->spriteSelected);
									}
								}
								
							}
						}
					}
				}

			}
			break;

		default:
			break;
		}
	}

}
update_status GUI_Inventory::Update()
{
	Retexture();
	if (App->input->mouse_buttons[SDL_BUTTON_LEFT] == KEY_STATE::KEY_DOWN) // if the user clicked a mousebutton
	{
		if (InventoryCharacter == NO_CHARACTER){
			if (App->gui->CheckButton(&Player1, App->input->mouse_x, App->input->mouse_y) && InventoryIs == OFF){
				InventoryIs = ON;
				InventoryCharacter = CHARACTER_ONE;
				Retexture();
			}
			else if (App->gui->CheckButton(&Player2, App->input->mouse_x, App->input->mouse_y) && InventoryIs == OFF){
				InventoryIs = ON;
				InventoryCharacter = CHARACTER_TWO;
				Retexture();
			}
			else if (App->gui->CheckButton(&Player3, App->input->mouse_x, App->input->mouse_y) && InventoryIs == OFF){
				InventoryIs = ON;
				InventoryCharacter = CHARACTER_THREE;
				Retexture();
			}
			else if (App->gui->CheckButton(&Player4, App->input->mouse_x, App->input->mouse_y) && InventoryIs == OFF){
				InventoryIs = ON;
				InventoryCharacter = CHARACTER_FOUR;
				Retexture();
			}
		}
		else{
			if (App->gui->CheckButton(&Exit, App->input->mouse_x, App->input->mouse_y) && InventoryIs == ON){
				InventoryIs = OFF;
				InventoryCharacter = NO_CHARACTER;
				Retexture();
			}
			else if (App->gui->CheckButton(&Arrow_left, App->input->mouse_x, App->input->mouse_y) && InventoryIs == ON){
				if (InventoryCharacter == CHARACTER_ONE)
					InventoryCharacter = CHARACTER_FOUR;
				else if (InventoryCharacter == CHARACTER_TWO)
					InventoryCharacter = CHARACTER_ONE;
				else if (InventoryCharacter == CHARACTER_THREE)
					InventoryCharacter = CHARACTER_TWO;
				else if (InventoryCharacter == CHARACTER_FOUR)
					InventoryCharacter = CHARACTER_THREE;
				Retexture();
			}
			else if (App->gui->CheckButton(&Arrow_right, App->input->mouse_x, App->input->mouse_y) && InventoryIs == ON){
				if (InventoryCharacter == CHARACTER_ONE)
					InventoryCharacter = CHARACTER_TWO;
				else if (InventoryCharacter == CHARACTER_TWO)
					InventoryCharacter = CHARACTER_THREE;
				else if (InventoryCharacter == CHARACTER_THREE)
					InventoryCharacter = CHARACTER_FOUR;
				else if (InventoryCharacter == CHARACTER_FOUR)
					InventoryCharacter = CHARACTER_ONE;
				Retexture();
			}
			else {
				switch (InventoryCharacter)
				{
				case CHARACTER_ONE:
					if (itemSelected(CHARACTER_ONE)){
						DoubleList<Item*>::nodeD* item = App->player->formation[CHARACTER_ONE]->inventory.first_node;
						for (int i = 0; i < MAX_SLOTS; i++){
							if (App->gui->CheckButton(&slots.Sloot[i], App->input->mouse_x, App->input->mouse_y) && InventoryIs == ON){
								for (; item != nullptr; item = item->next){
									if (item->data->isSelected == true){
										if (!isOcuped(CHARACTER_ONE, i)){
											item->data->itemSlot = i;
											item->data->isSelected = false;
										}
										else{
											swapItems(CHARACTER_ONE, item->data->itemSlot, i);
										}
									}
								}
							}
						}
					}
					else{
						DoubleList<Item*>::nodeD* item = App->player->formation[CHARACTER_ONE]->inventory.first_node;
						for (int i = 0; i < MAX_SLOTS; i++){
							if (App->gui->CheckButton(&slots.Sloot[i], App->input->mouse_x, App->input->mouse_y) && InventoryIs == ON){
								for (; item != nullptr; item = item->next){
									if (item->data->itemSlot == i){
										item->data->isSelected = true;

									}
								}
							}
						}
					}
					break;
				case CHARACTER_TWO:
					if (itemSelected(CHARACTER_TWO)){
						DoubleList<Item*>::nodeD* item = App->player->formation[CHARACTER_TWO]->inventory.first_node;
						for (int i = 0; i < MAX_SLOTS; i++){
							if (App->gui->CheckButton(&slots.Sloot[i], App->input->mouse_x, App->input->mouse_y) && InventoryIs == ON){
								for (; item != nullptr; item = item->next){
									if (item->data->isSelected == true){
										if (!isOcuped(CHARACTER_TWO, i)){
											item->data->itemSlot = i;
											item->data->isSelected = false;
										}
										else{
											swapItems(CHARACTER_TWO, item->data->itemSlot, i);
										}
									}
								}
							}
						}
					}
					else{
						DoubleList<Item*>::nodeD* item = App->player->formation[CHARACTER_TWO]->inventory.first_node;
						for (int i = 0; i < MAX_SLOTS; i++){
							if (App->gui->CheckButton(&slots.Sloot[i], App->input->mouse_x, App->input->mouse_y) && InventoryIs == ON){
								for (; item != nullptr; item = item->next){
									if (item->data->itemSlot == i){
										item->data->isSelected = true;
									}
								}
							}
						}
					}
					break;
				case CHARACTER_THREE:
					if (itemSelected(CHARACTER_THREE)){
						DoubleList<Item*>::nodeD* item = App->player->formation[CHARACTER_THREE]->inventory.first_node;
						for (int i = 0; i < MAX_SLOTS; i++){
							if (App->gui->CheckButton(&slots.Sloot[i], App->input->mouse_x, App->input->mouse_y) && InventoryIs == ON){
								for (; item != nullptr; item = item->next){
									if (item->data->isSelected == true){
										if (!isOcuped(CHARACTER_THREE, i)){
											item->data->itemSlot = i;
											item->data->isSelected = false;
										}
										else{
											swapItems(CHARACTER_THREE, item->data->itemSlot, i);
										}
									}
								}
							}
						}
					}
					else{
						DoubleList<Item*>::nodeD* item = App->player->formation[CHARACTER_THREE]->inventory.first_node;
						for (int i = 0; i < MAX_SLOTS; i++){
							if (App->gui->CheckButton(&slots.Sloot[i], App->input->mouse_x, App->input->mouse_y) && InventoryIs == ON){
								for (; item != nullptr; item = item->next){
									if (item->data->itemSlot == i){
										item->data->isSelected = true;
									}
								}
							}
						}
					}
					break;
				case CHARACTER_FOUR:
					if (itemSelected(CHARACTER_FOUR)){
						DoubleList<Item*>::nodeD* item = App->player->formation[CHARACTER_FOUR]->inventory.first_node;
						for (int i = 0; i < MAX_SLOTS; i++){
							if (App->gui->CheckButton(&slots.Sloot[i], App->input->mouse_x, App->input->mouse_y) && InventoryIs == ON){
								for (; item != nullptr; item = item->next){
									if (item->data->isSelected == true){
										if (!isOcuped(CHARACTER_FOUR, i)){
											item->data->itemSlot = i;
											item->data->isSelected = false;
										}
										else{
											swapItems(CHARACTER_FOUR, item->data->itemSlot, i);
										}
									}
								}
							}
						}
					}
					else{
						DoubleList<Item*>::nodeD* item = App->player->formation[CHARACTER_FOUR]->inventory.first_node;
						for (int i = 0; i < MAX_SLOTS; i++){
							if (App->gui->CheckButton(&slots.Sloot[i], App->input->mouse_x, App->input->mouse_y) && InventoryIs == ON){
								for (; item != nullptr; item = item->next){
									if (item->data->itemSlot == i){
										item->data->isSelected = true;
									}
								}
							}
						}
					}
					break;
				case NO_CHARACTER:
					break;
				default:
					break;
				}

			}
		}
	}
		return UPDATE_CONTINUE;

	
}
bool GUI_Inventory::itemSelected(currentCharracter characterNumber){
	bool ret = false;
	DoubleList<Item*>::nodeD* item = App->player->formation[characterNumber]->inventory.first_node;
	for (; item != nullptr; item = item->next){
		if (item->data->isSelected == true){
			ret = true;
			return ret;
		}
	}
	return ret;
}
bool GUI_Inventory::isOcuped(currentCharracter characterNumber,int slot){
	bool ret = false;
	DoubleList<Item*>::nodeD* item = App->player->formation[characterNumber]->inventory.first_node;
	for (; item != nullptr; item = item->next){
		if (item->data->itemSlot == slot){
			ret = true;
			return ret;
		}
	}
	return ret;
}
void GUI_Inventory::swapItems(currentCharracter characterNumber,int location, int destiny){
	DoubleList<Item*>::nodeD* item = App->player->formation[characterNumber]->inventory.first_node;
	for (; item != nullptr; item = item->next){
		if (item->data->itemSlot == destiny){
			item->data->itemSlot = location;
		}
		if (item->data->isSelected == true){
			item->data->itemSlot = destiny;
			item->data->isSelected = false;
		}
	}
}
Character_Icon::Character_Icon(){
	int i = 0;
	Sloot[i++] = { 617, 220, 52, 52 };
	Sloot[i++] = { 675, 220, 52, 52 };
	Sloot[i++] = { 733, 220, 52, 52 };
	Sloot[i++] = { 617, 278, 52, 52 };
	Sloot[i++] = { 675, 278, 52, 52 };
	Sloot[i++] = { 733, 278, 52, 52 };
	Sloot[i++] = { 617, 336, 52, 52 };
	Sloot[i++] = { 675, 336, 52, 52 };
	Sloot[i++] = { 733, 336, 52, 52 };
	Sloot[i++] = { 739, 16, 52, 52 };
	Sloot[i++] = { 739, 82, 52, 52 };
	Sloot[i++] = { 739, 148, 52, 52 };

}
Inventory::Inventory(){

}