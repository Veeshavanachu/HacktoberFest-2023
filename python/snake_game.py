import pygame
import random

# Initialize Pygame
pygame.init()

# Color definitions
WHITE = (255, 255, 255)
YELLOW = (255, 255, 102)
BLACK = (0, 0, 0)
RED = (213, 50, 80)
GREEN = (0, 255, 0)
BLUE = (50, 153, 213)

# Display dimensions
WIDTH, HEIGHT = 600, 400
display = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption('Snake Game')

# Game clock and snake settings
clock = pygame.time.Clock()
SNAKE_BLOCK = 10
SNAKE_SPEED = 15  # Adjusted for a slower pace

# Fonts
font_style = pygame.font.SysFont("bahnschrift", 25)
score_font = pygame.font.SysFont("comicsansms", 35)

# Function to display score
def display_score(score):
    score_text = score_font.render(f"Your Score: {score}", True, YELLOW)
    display.blit(score_text, [0, 0])

# Function to draw the snake
def draw_snake(snake_blocks):
    for block in snake_blocks:
        pygame.draw.rect(display, BLACK, [block[0], block[1], SNAKE_BLOCK, SNAKE_BLOCK])

# Function to show messages
def show_message(msg, color):
    message = font_style.render(msg, True, color)
    display.blit(message, [WIDTH / 6, HEIGHT / 3])

# Main game loop function
def game_loop():
    game_over = False
    game_close = False

    x, y = WIDTH / 2, HEIGHT / 2
    x_change, y_change = 0, 0

    snake_blocks = []
    snake_length = 1

    food_x = round(random.randrange(0, WIDTH - SNAKE_BLOCK) / 10.0) * 10.0
    food_y = round(random.randrange(0, HEIGHT - SNAKE_BLOCK) / 10.0) * 10.0

    while not game_over:
        while game_close:
            display.fill(BLUE)
            show_message("You Lost! Press C-Play Again or Q-Quit", RED)
            display_score(snake_length - 1)
            pygame.display.update()

            for event in pygame.event.get():
                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_q:
                        game_over = True
                        game_close = False
                    elif event.key == pygame.K_c:
                        game_loop()

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                game_over = True
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    x_change = -SNAKE_BLOCK
                    y_change = 0
                elif event.key == pygame.K_RIGHT:
                    x_change = SNAKE_BLOCK
                    y_change = 0
                elif event.key == pygame.K_UP:
                    y_change = -SNAKE_BLOCK
                    x_change = 0
                elif event.key == pygame.K_DOWN:
                    y_change = SNAKE_BLOCK
                    x_change = 0

        if x >= WIDTH or x < 0 or y >= HEIGHT or y < 0:
            game_close = True

        x += x_change
        y += y_change

        display.fill(BLUE)
        pygame.draw.rect(display, GREEN, [food_x, food_y, SNAKE_BLOCK, SNAKE_BLOCK])

        snake_head = [x, y]
        snake_blocks.append(snake_head)

        if len(snake_blocks) > snake_length:
            del snake_blocks[0]

        for block in snake_blocks[:-1]:
            if block == snake_head:
                game_close = True

        draw_snake(snake_blocks)
        display_score(snake_length - 1)

        pygame.display.update()

        if x == food_x and y == food_y:
            food_x = round(random.randrange(0, WIDTH - SNAKE_BLOCK) / 10.0) * 10.0
            food_y = round(random.randrange(0, HEIGHT - SNAKE_BLOCK) / 10.0) * 10.0
            snake_length += 1

        clock.tick(SNAKE_SPEED)

    pygame.quit()

# Start the game
if __name__ == "__main__":
    game_loop()
