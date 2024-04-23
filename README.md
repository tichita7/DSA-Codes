# Linux Command and SQL Query Generator

GenShell is a Python project that utilizes generative AI to generate Linux commands and SQL queries based on the input provided.
## Overview

This project aims to assist users in generating Linux commands and SQL queries for various purposes. It utilizes machine learning techniques to generate coherent and relevant commands and queries based on the provided input.

## Features

- Input-driven Command and Query Generation: Users can input a prompt or context, and the AI generates a Linux command or SQL query relevant to that input.
- Customization: Users can adjust the parameters of the AI model to fine-tune the generated commands and queries.
- Multiple Applications: The generated commands and queries can be used for scripting, database management, system administration, and more.
- Easy-to-Use Interface: Simple command-line interface for generating commands and queries quickly.

## Installation

1. Clone this repository:

    ```
    git clone https://github.com/your-username/linux-sql-generator.git
    ```

2. Navigate to the project directory:

    ```
    cd linux-sql-generator
    ```

3. Install the required dependencies:

    ```
    pip install -r requirements.txt
    ```

## Usage

1. Run the command generator script:

    ```
    python command_generator.py
    ```

2. Follow the prompts to input your context or prompt.

3. The AI will generate a Linux command or SQL query based on your input.

## Configuration

You can adjust the following parameters in `config.py`:

- `MODEL_TYPE`: Specify the type of generative AI model to use.
- `MODEL_PARAMS`: Set parameters for the selected model.
- `INPUT_LENGTH`: Define the maximum length of the input prompt.
- `OUTPUT_LENGTH`: Define the maximum length of the generated command or query.
- `NUM_GENERATIONS`: Number of command/query generations to produce.
- `TEMPERATURE`: Temperature parameter for controlling randomness in generation.

## Examples

- Linux Command:
  
  ```
  Input: "List all files in the current directory"
  Output: "ls -l"
  ```

- SQL Query:

  ```
  Input: "Retrieve all employees from the 'HR' department"
  Output: "SELECT * FROM employees WHERE department = 'HR';"
  ```

## Contributors

- Akshat Mittal
- Tichita
- Varun Prohit

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.



##Another one

# GenShell: AI Integrated Shell

## Overview

GenShell is an AI Integrated Shell designed to enhance the user experience by integrating the power of artificial intelligence directly into the terminal of your system. By incorporating the GenAI tool, GenShell provides intelligent command suggestions and facilitates seamless database configuration and querying directly from the terminal window.

## Features

- **Integration of GenAI Tool**: GenShell seamlessly integrates the GenAI tool into the terminal interface, allowing users to leverage the capabilities of artificial intelligence for enhanced productivity and efficiency.

- **Intelligent Command Suggestions**: GenShell provides relevant command suggestions based on user input, streamlining the command-line experience and reducing errors.

- **Database Configuration**: Users can configure databases directly from the terminal, simplifying the setup process and saving time.

- **Query Results**: GenShell enables users to execute database queries from the terminal and receive relevant results, eliminating the need to switch between different applications.

## Installation

1. Clone this repository:

    ```bash
    git clone https://github.com/your-username/genshell.git
    ```

2. Navigate to the project directory:

    ```bash
    cd genshell
    ```

3. Install the required dependencies:

    ```bash
    pip install -r requirements.txt
    ```

## Usage

1. Run GenShell:

    ```bash
    python genshell.py
    ```

2. Follow the prompts to interact with GenShell.

## Configuration

You can configure GenShell by editing the settings in `config.py`.

## Examples

- **Intelligent Command Suggestion**:


git add .
git commit -m "chit"
git push

  


