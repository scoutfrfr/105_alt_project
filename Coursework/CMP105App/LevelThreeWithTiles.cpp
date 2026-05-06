#include "LevelThreeWithTiles.h"

LevelThreeWithTiles::LevelThreeWithTiles(sf::RenderWindow& window, Input& input, GameState& gameState, AudioManager& audio)
	: Scene(window, input, gameState, audio), m_alertText(m_font)
{

	GameObject tile;
	std::vector<GameObject> tileSet;

	int num_columns = 20;
	int num_rows = 9;
	int tile_size = 18;      // Visual size of the tile
	int sheet_spacing = 1;   // Gap between tiles


	// Set GameObject size (Scaling up 4x for visibility)
	// 4 * 18 = 3 * 24 = 72 (dino size is 24).
	tile.setSize(sf::Vector2f(tile_size * 4, tile_size * 4));
	tile.setCollisionBox({ { 0,0 }, tile.getSize() });

	for (int i = 0; i < num_columns * num_rows; i++)
	{
		int row = i / num_columns;
		int col = i % num_columns;

		tile.setTextureRect({
			{(tile_size + sheet_spacing) * col, (tile_size + sheet_spacing) * row},
			{tile_size, tile_size} });
		if (col <= 4 || col >= 12) tile.setCollider(true);
		else tile.setCollider(false);
		tileSet.push_back(tile);
	}

	// Add Blank
	tile.setTextureRect({ {0, 0}, {-24, -24} }); // Empty rect for blank
	int b = tileSet.size();
	tile.setCollider(false);
	tileSet.push_back(tile);

	sf::Vector2u mapDimensions{ 40, 8 };
	std::vector<int> tileMap = {
		b  , b   , b  , b  , b  , b  , b  , b  , b  , b  , b  , b  , b  , b  , b  , b  , b  , b  , b  , b  , b  , b  , b, b, b,  b,  b, b, b, b, b, b  , b  , b  , b  , b  , b  , b  , b  , b  ,
		b  , b   , b  , b  , b  , 17 , 18 , 19 , b  , b  , b  , b  , b  , b  , 17 , 18 , 19 , b  , b  , b  , b  , b  , b, b, b,  b,  b, b, b, b, b, b  , b  , b  , b  , b  , b  , b  , b  , b  ,
		b  , b   , b  , b  , b  , 37 , 38 , 39 , b  , b  , b  , b  , 17 , 18 , 38 , 38 , 39 , b  , b  , b  , b  , b  , b, b, 17, 18, 19,b, b, b, b, b  , b  , b  , b  , b  , b  , b  , b  , b  ,
		b  , b   , b  , b  , b  , 57 , 97 , 59 , b  , b  , b  , b  , 57 , 38 , 38 , 38 , 59 , b  , b  , b  , b  , b  , b, b, 37, 38, 39,b, b, b, b, b  , b  , b  , b  , b  , b  , b  , b  , b  ,
		17 , 18  , 19 , b  , b  , b  , 116 ,b  , b  , b  , b  , b  , b  , 57 , 97 , 59 , b  , b  , b  , b  , b  , b  , b, b, 57, 97, 59,b, b, b, b, b  , b  , b  , b  , b  , b  , b  , 131, b  ,
		57 , 97  , 59 , b  , b  , b  , 116, b  , b  , b  , b  , b  , b  , b  , 116, b  , b  , b  , b  , b  , b  , b  , b, b, b, 116, b, b, b, b, b, b  , 61 , 62 , 62 , 62 , 62 , 62 , 62 , 63 ,
		118, 117 , 139, b  , b  , b  , 116, b  , b  , b  , b  , b  , b  , b  , 116, b  , b  , b  , b  , b  , b  , b  , b, b, b, 116, b, b, b, b, b, b  , 121, 122, 122, 122, 122, 122, 122, 123,
		b,   137 , b  , b  , b  , b  , 137, b  , b  , b  , b  , b  , b  , b  , 137, b  , b  , b  , b  , b  , b  , b  , b, b, b, 137, b, b, b, b, b, b  , 121, 122, 122, 122, 122, 122, 122, 123
	};

	m_tilemap.loadTexture("gfx/tilemap.png");
	m_tilemap.setTileSet(tileSet);
	m_tilemap.setTileMap(tileMap, mapDimensions);
	m_tilemap.setPosition({ 0, 100 });
	m_tilemap.buildLevel();

	tileSet.clear();

	// setup background
	tile_size = 24;
	num_columns = 8;
	num_rows = 3;
	// 24 * 9 = 216, a multiple of 72, the LCM of the player and tile size.
	tile.setSize(sf::Vector2f(tile_size * 9, tile_size * 9));

	for (int i = 0; i < num_columns * num_rows; i++)
	{
		int row = i / num_columns;
		int col = i % num_columns;

		tile.setTextureRect({
			{(tile_size + sheet_spacing) * col, (tile_size + sheet_spacing) * row},
			{tile_size, tile_size} });
		tile.setCollider(false);		// don't collide with background
		tileSet.push_back(tile);
	}

	mapDimensions = { 14,5 };
	tileMap = {
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
		20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
		20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20
	};

	m_bgtilemap.loadTexture("gfx/tilemap-backgrounds.png");
	m_bgtilemap.setTileSet(tileSet);
	m_bgtilemap.setTileMap(tileMap, mapDimensions);
	m_bgtilemap.setPosition({ 0, 0 });
	m_bgtilemap.buildLevel();

	// setup player 
	m_player.setInput(&m_input);
	m_player.setEdges(0, WORLD_SIZE.x);
	m_player.setCurrentHealth(3);

	// setup enemies
	std::vector<sf::Vector2f> enemy_locations = {
		{908, 181}
	};

	for (int i = 0; i < 1; i++)
	{
		Enemy* new_enemy = new Enemy;
		new_enemy->setPosition(enemy_locations[i]);
		new_enemy->setEdges(0, WORLD_SIZE.x);
		m_enemyPointers.push_back(new_enemy);
	}

	//m setup text
	if (!m_font.openFromFile("font/bitcount.ttf")) std::cerr << "no font found";
	m_alertText.setString("'Have to get past\nthese trees to get\nto the flag!'");
	m_alertText.setPosition({ 20, 200 });
	m_alertText.setCharacterSize(32);
	m_alertText.setFillColor(sf::Color::Black);
	m_promptTimer = PROMPT_TIME;
	if (!m_tileTexture.loadFromFile("gfx/tilemap.png")) std::cerr << "no tile image found";

	// setup flags and end game pos
	m_flag.setPosition({ 38 * 72, 5 * 72 });
	m_flag.setSize({ 72,72 });
	m_flag.setTexture(&m_tileTexture);
	m_player.setAudio(&m_audio);

}

void LevelThreeWithTiles::handleInput(float dt)
{

	m_player.handleInput(dt);

	if (m_input.isPressed(sf::Keyboard::Scancode::Escape))
	{
		/*m_gameState.setCurrentState(State::PAUSE);*/
		if (m_gamePaused == false)
		{
			m_gamePaused = true;
		}
		else
		{
			m_gamePaused = false;
		}
	}

	// if I press F on the flag  / I press escape.
	if (((m_flag.getPosition() - m_player.getPosition()).length() < 75 &&
		m_input.isPressed(sf::Keyboard::Scancode::F)))
	{
		// Go to next level
		m_gameState.setCurrentState(State::LEVELFOUR);
	}

}

void LevelThreeWithTiles::update(float dt)
{

	m_flag.update(dt);
;

	if (m_gamePaused == false)
	{
		m_player.update(dt);
	}


	std::vector<GameObject>& level = *m_tilemap.getLevel();
	for (auto& t : level)
	{
		if (t.isCollider() && Collision::checkBoundingBox(m_player, t))
		{
			m_player.collisionResponse(t);
		}

	}

	if (!m_enemyDead)
	{
		for (auto enemy : m_enemyPointers)
		{
			enemy->update(dt);
		}

		for (auto enemy : m_enemyPointers)
		{
			if (Collision::checkBoundingBox(*enemy, m_player))
			{
				if (m_player.playerAttack() == false)
				{
					m_player.takeDamage();
				}
				else
				{
					enemy->setAlive(false);
					m_enemyDead = true;
				}
			}
		}
	}


	// reset if fallen too far
	if (m_player.getPosition().y > 1200)
	{
		m_player.takeDamage();
		m_player.reset();
		m_audio.playSoundbyName("death");


	}

	// resets if player dies and changes states
	if (m_player.playerDeath() == true)
	{
		m_player.reset();
		m_gameState.setCurrentState(State::GAMEOVER);

	}


	// camera follows player, bounded.
	updateCameraAndBackground();
	checkAndSetMessages();

}

void LevelThreeWithTiles::updateCameraAndBackground()
{

	auto view = m_window.getView();
	auto player_pos = m_player.getPosition() + m_player.getSize() * 0.5f;

	float halfViewWidth = VIEW_SIZE.x / 2.0f;
	float halfViewHeight = VIEW_SIZE.y / 2.0f;

	player_pos.x = std::clamp(player_pos.x, halfViewWidth, WORLD_SIZE.x - halfViewWidth);
	player_pos.y = std::clamp(player_pos.y, halfViewHeight, WORLD_SIZE.y - halfViewHeight);

	view.setCenter(player_pos);
	m_window.setView(view);

	m_bgtilemap.setPosition({ player_pos.x - halfViewWidth, 0 });

}

void LevelThreeWithTiles::checkAndSetMessages()
{
	// get position 25% in from top and left (get middle, half both dimensions)
	sf::Vector2f inner_top_left = m_window.getView().getCenter();
	sf::Vector2f window_size = {
		static_cast<float>(m_window.getSize().x),
		static_cast<float>(m_window.getSize().y) };
	inner_top_left -= window_size * 0.25f;
	if ((m_flag.getPosition() - m_player.getPosition()).length() < 75)
	{
		m_alertText.setCharacterSize(24);
		m_alertText.setPosition(inner_top_left);
		m_alertText.setString("Press F to end the day");
	}

}

void LevelThreeWithTiles::render()
{

	if (m_gamePaused == false)
	{
		beginDraw();
		m_bgtilemap.render(m_window);
		m_tilemap.render(m_window);
		m_window.draw(m_flag);
		m_window.draw(m_player);
		m_window.draw(m_alertText);
		if (!m_enemyDead)
		{
			for (auto enemy : m_enemyPointers) m_window.draw(*enemy);
		}
		m_ui.drawUI(m_window, m_player);
		endDraw();
	}

}

void LevelThreeWithTiles::onBegin()
{
	m_player.setCanDoubleJump(true);
	m_enemyDead = false;
	m_gamePaused = false;
	std::cout << "Level three has been started\n";
	m_audio.playMusicbyName("bgm1");

}

void LevelThreeWithTiles::onEnd()
{

	if (!m_gamePaused)
	{
		std::cout << "Level three has been left\n";
		// reset player and level state
		m_player.reset();
		m_enemyDead = false;
		// reset alert text
		m_alertText.setString("'Have to get past\nthese trees to get\nto the flag!'");
		m_alertText.setPosition({ 50, 150 });
		m_alertText.setCharacterSize(36);
		m_alertText.setFillColor(sf::Color::Black);
		m_promptTimer = PROMPT_TIME;
		// sfx
		m_audio.stopAllSounds();
		m_audio.stopAllMusic();
	}

}
