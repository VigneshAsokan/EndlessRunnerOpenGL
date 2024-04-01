#pragma once
#include <engine.h>
#include "engine/entities/bounding_box.h"
#include "Billboard.h"

class turret_enemy
{
	enum class state
	{
		idle,
		Shoot
	};
public:
	turret_enemy();
	~turret_enemy();

	void on_update(const engine::timestep& time_step, const glm::vec3& player_position);
	void init(engine::ref<engine::game_object> object);
	engine::ref<engine::game_object> object() const { return m_object; }
	void on_render(const engine::ref<engine::shader>& shader, const engine::perspective_camera& camera);
	bool Check_Bullet_collision(const engine::bounding_box& playerbox);
	void TakeDamage(int damage);
private:
	glm::vec3													m_init_position;
	float														m_shootTimer = 0.f;
	engine::ref< engine::game_object>							m_object;
	engine::ref<Billboard>										m_health_bar;
	int															m_health = 100;
	engine::ref<Billboard>										m_explosionFX{};
	engine::ref<engine::game_object>							m_bullet{};
	engine::bounding_box										m_Bullet_box;
	float														m_radar_distance{ 20.f };
	float														m_respawnTimer = 0;
	bool														m_respawn = false;

	void face_Player(const engine::timestep& time_step, const glm::vec3& player_position);
	void Shoot_player();
	void disableBullet();
	void DisableEnemy();
	void Respawn();
	//Current EnemyState
	state m_state = state::idle;

};
