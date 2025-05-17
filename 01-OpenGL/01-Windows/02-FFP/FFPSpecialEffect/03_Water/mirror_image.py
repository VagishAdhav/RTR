from PIL import Image

# Load your original texture
original = Image.open("water.bmp")  # Replace with your file name

# Create a horizontally flipped copy
flipped = original.transpose(Image.FLIP_LEFT_RIGHT)

# Create a new image with double width
width, height = original.size
combined = Image.new("RGBA", (width * 2, height))

# Paste the original and flipped side by side
combined.paste(original, (0, 0))
combined.paste(flipped, (width, 0))

# Save the result
combined.save("water2.bmp")
print("Saved as water2.bmp")