import PyInstaller.__main__

# Path to your Python script
script_path = "System_Stability_Check/app.py"

# PyInstaller options (optional)
pyinstaller_options = [
    "--onefile",  # Create a single executable file
    "--name", "my_app",  # Set the name of the executable
    # Add more options as needed
]

# Call PyInstaller programmatically
PyInstaller.__main__.run([
    script_path,
    *pyinstaller_options
])