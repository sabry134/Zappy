/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** zappy_server.h
*/

#ifndef _ZAPPY_SERVER_H_
    #define _ZAPPY_SERVER_H_

    #define ZAPPY_SERVER_MAX_CLIENTS 100
    #define ZAPPY_SERVER_BUFFER_SIZE 1024
    #define ZAPPY_SERVER_GRAPHICAL_COMMANDS_COUNT 9
    #define ZAPPY_SERVER_PLAYER_COMMANDS_COUNT 12
    #define ZAPPY_SERVER_FOOD_UNITS 126
    #define ZAPPY_SERVER_RESOURCES_UNITS 20

    #include <arpa/inet.h>
    #include <sys/select.h>
    #include <sys/types.h>
    #include <time.h>

typedef struct zappy_server_s zappy_server_t;

typedef struct zappy_pcmd_s zappy_pcmd_t;

typedef struct zappy_egg_s {
    int id;
    int player_id;
    unsigned int x;
    unsigned int y;
    struct zappy_egg_s *next;
} zappy_egg_t;

typedef struct zappy_team_s {
    char *name;
    int slot;
    zappy_egg_t *eggs;
    struct zappy_team_s *next;
} zappy_team_t;

typedef struct zappy_player_cmd_s {
    zappy_pcmd_t *pcmd;
    char data[64];
} zappy_player_cmd_t;

typedef struct zappy_player_s {
    int id;
    unsigned int x;
    unsigned int y;
    unsigned int rot;
    int lvl;
    int inventory[7];
    int elevation;
    zappy_team_t *team;
    zappy_player_cmd_t cmds[10];
    struct timespec cmd_start;
    struct timespec hunger;
} zappy_player_t;

typedef struct zappy_client_s {
    int sockfd;
    int sockclose;
    char address[INET_ADDRSTRLEN];
    uint16_t port;
    char buffer[ZAPPY_SERVER_BUFFER_SIZE];
    ssize_t pending;
    zappy_player_t player;
    int graphic;
    zappy_server_t *server;
} zappy_client_t;

typedef struct zappy_gcmd_s {
    char name[4];
    void (*func)(zappy_client_t *, char *);
} zappy_gcmd_t;

struct zappy_pcmd_s {
    char name[12];
    int time_limit;
    void (*func)(zappy_client_t *, char *);
    int (*start)(zappy_client_t *);
};

struct zappy_server_s {
    int port;
    int width;
    int height;
    zappy_team_t *teams;
    int clientsNb;
    int freq;
    int sockfd;
    int signalfd;
    zappy_client_t clients[ZAPPY_SERVER_MAX_CLIENTS];
    zappy_gcmd_t graphical_commands[ZAPPY_SERVER_GRAPHICAL_COMMANDS_COUNT];
    zappy_pcmd_t player_commands[ZAPPY_SERVER_PLAYER_COMMANDS_COUNT];
    zappy_pcmd_t incantation_wait;
    int map[30][30][7];
    struct timespec now;
    struct timespec resources;
    int close;
};

typedef struct zappy_opt_s {
    int c;
    int (*func)(int, int, int);
} zappy_opt_t;

int tile_content(zappy_client_t *client, int x, int y);
void graphical_bct(zappy_client_t *client, char *data);
void graphical_mct(zappy_client_t *client, char *data);
void graphical_msz(zappy_client_t *client, char *data);
void graphical_pin(zappy_client_t *client, char *data);
void graphical_plv(zappy_client_t *client, char *data);
void graphical_ppo(zappy_client_t *client, char *data);
void graphical_sgt(zappy_client_t *client, char *data);
void graphical_sst(zappy_client_t *client, char *data);
void graphical_tna(zappy_client_t *client, char *data);

void player_connect_nbr(zappy_client_t *client, char *data);
void player_eject(zappy_client_t *client, char *data);
int egg_laying(zappy_client_t *client);
void player_fork(zappy_client_t *client, char *data);
void forward(zappy_client_t *client, int rot);
void player_forward(zappy_client_t *client, char *data);
int can_elevation_start(zappy_client_t *client);
void player_incantation(zappy_client_t *client, char *data);
void player_inventory(zappy_client_t *client, char *data);
void player_left(zappy_client_t *client, char *data);
void player_look(zappy_client_t *client, char *data);
void player_right(zappy_client_t *client, char *data);
void player_set(zappy_client_t *client, char *data);
void player_take(zappy_client_t *client, char *data);
void broadcast(zappy_client_t *client, char *data);
void print_direction_nord(zappy_client_t *cli, int x, int y);
void print_direction_east(zappy_client_t *cli, int x, int y);
void print_direction_sud(zappy_client_t *cli, int x, int y);
void print_direction_west(zappy_client_t *cli, int x, int y);

void commands_graphical(zappy_client_t* client, char* data);
void commands_player(zappy_client_t* client, char* data);

zappy_egg_t *spawn_egg(zappy_client_t *client);
zappy_egg_t* get_random_egg(zappy_team_t *team);
void free_eggs(zappy_team_t *team);

void game_loop(zappy_server_t *server);

int player_equals_incantation(zappy_client_t *c1, zappy_client_t *c2
, int elevation);
int nb_players_incantation(zappy_client_t *client, int elevation);
int already_incantating(zappy_client_t *client);

zappy_player_t *get_player_by_id(zappy_server_t *server, int id);
void add_player_command(zappy_client_t* client, zappy_pcmd_t *pcmd, char *data);
void kill_player(zappy_client_t *client);
int get_nb_players_team(zappy_server_t *server, zappy_team_t *team);

void spawn_resources(zappy_server_t *server);
int get_resource_index(const char *str);
char *get_resource_name(int i);

int time_is_up(zappy_server_t *server, struct timespec ts, double time_limit);
struct timeval get_remaining_time(zappy_server_t *server, struct timespec ts
, double time_limit);

void graphical_ebo(zappy_server_t *server, zappy_egg_t *egg);
void graphical_edi(zappy_server_t *server, zappy_egg_t *egg);
void graphical_enw(zappy_server_t *server, zappy_egg_t *egg);
void graphical_enw_c(zappy_client_t *client, zappy_egg_t *egg);
void graphical_pbc(zappy_server_t *server, zappy_player_t *player, char *br);
void graphical_pdi(zappy_server_t *server, zappy_player_t *player);
void graphical_pdr(zappy_server_t *server, zappy_player_t *player, int i);
void graphical_pex(zappy_server_t *server, zappy_player_t *player);
void graphical_pfk(zappy_server_t *server, zappy_player_t *player);
void graphical_pgt(zappy_server_t *server, zappy_player_t *player, int i);
void graphical_pic(zappy_server_t *server, zappy_client_t *client);
void graphical_pie(zappy_server_t *server, zappy_player_t *player, int res);
void graphical_pnw(zappy_server_t *server, zappy_player_t *player);
void graphical_pnw_c(zappy_client_t *client, zappy_player_t *player);
void graphical_seg(zappy_server_t *server, char *team_name);

void graphical_join(zappy_client_t *client);
void graphical_write(zappy_server_t *server, const char *fmt, ...);

void read_client(zappy_client_t *client);

void add_client(zappy_server_t *server, zappy_client_t *client, int sockfd
, struct sockaddr_in *addr_in);
void remove_client(zappy_client_t *client);

int listen_sockets(zappy_server_t *server);

int read_select(zappy_server_t *server, fd_set *readfds);

int start_server(zappy_server_t *server);
void stop_server(zappy_server_t *server);

int check_opt_p(int is_number, int num, int c);
int check_opt_xy(int is_number, int num, int c);
int check_opt_c(int is_number, int num, int c);
int check_opt_f(int is_number, int num, int c);

int parse_args(int argc, char *argv[], zappy_server_t *server);

int check_help(int argc, char *argv[]);

void setup_signal(zappy_server_t *server);

int parse_team_names(char *argv[], zappy_server_t *server);
zappy_team_t *get_team(zappy_server_t *server, char *team_name);
void free_teams(zappy_server_t *server);

int is_number(char* str);
int modulo(int num, int div);

#endif
