#include "SceneStory3.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleUI.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

#include <stdio.h>

SceneStory3::SceneStory3(bool startEnabled) : Module(startEnabled)
{

}

SceneStory3::~SceneStory3()
{

}

// Load assets
bool SceneStory3::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	texture = App->textures->Load("Assets/Intro/prueba.png");
	App->audio->PlayMusic("Assets/Music/Intro.ogg", 1.0f);


	App->render->camera.x = 0;
	App->render->camera.y = 0;


	return ret;
}

update_status SceneStory3::Update()
{
	App->fade->FadeToBlack(this, (Module*)App->scenestory4, 90);
	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->scenePlayerSelect, 90);
	}

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status SceneStory3::PostUpdate()
{
	App->render->Blit(texture, -492, -347, NULL);

	return update_status::UPDATE_CONTINUE;
}

bool SceneStory3::CleanUp()
{
	//App->textures->Unload(bgTexture);
	App->textures->Unload(texture);

	return true;
}