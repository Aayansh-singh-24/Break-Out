#include"GameLevel.h"

void GameLevel::Load(const char* file, unsigned int levelWidth, unsigned int levelHeight)
{
    // clear old data
    this->Bricks.clear();
    // load from file
    unsigned int tileCode;
    GameLevel level;
    std::string line;
    std::ifstream fstream(file);
    std::vector<std::vector<unsigned int>> tileData;
    if (fstream)
    {
        while (std::getline(fstream, line)) // read each line from level file
        {
            std::istringstream sstream(line);
            std::vector<unsigned int> row;
            while (sstream >> tileCode) // read each word separated by spaces
                row.push_back(tileCode);
            tileData.push_back(row);
        }
        if (tileData.size() > 0)
            this->Init(tileData, levelWidth, levelHeight);
    }
}

void GameLevel::Init(std::vector<std::vector<unsigned int>>tileData, unsigned int levelWidth, unsigned levelHeight)
{
    unsigned int width = tileData.size();
    unsigned int height = tileData[0].size();

    unsigned unit_width = levelWidth /(float) width;
    unsigned int unit_height = levelHeight /(float) height;

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (tileData[i][j] == 1)
            {
                //-----------------Solid-Block--------------------------------
                glm::vec2 position = glm::vec2(unit_width * i, unit_height * j);
                glm::vec2 size = glm::vec2(unit_width, unit_height);
                Texture2D sprite = ResourceManager::GetTexture("block_solid");
                glm::vec3 color = glm::vec3(0.8f, 0.8f, 0.7f);
                glm::vec2 velocity = glm::vec2(0.0f, 0.0f);
                GameObject obj(sprite, position, size, color, velocity);
                obj.IsSolid = true;
                this->Bricks.push_back(obj);
            }
            else if (tileData[i][j] > 1)
            {
                glm::vec3 color= glm::vec3(1.0f, 1.0f, 1.0f); //Initial Color is White
                if(tileData[i][j]==2)
                    color = glm::vec3(0.2f, 0.6f, 1.0f);
                else if(tileData[i][j]==3)
                    color = glm::vec3(0.0f, 0.7f, 0.0f);
                else if (tileData[i][j] == 4)
                    color = glm::vec3(0.8f, 0.8f, 0.4f);
                else if (tileData[i][j] == 5)
                    color = glm::vec3(1.0f, 0.5f, 0.0f);


                glm::vec2 position = glm::vec2(unit_width * i, unit_height * j);
                glm::vec2 size = glm::vec2(unit_width, unit_height);
                glm::vec2 velocity = glm::vec2(0.0f, 0.0f);
                Texture2D sprite = ResourceManager::GetTexture("block_solid");
                GameObject obj(sprite, position, size, color, velocity);
                obj.IsSolid = true;
                this->Bricks.push_back(obj);
            }
        }
    }
}