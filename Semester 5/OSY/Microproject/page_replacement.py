import tkinter as tk
from tkinter import ttk
import numpy as np
import matplotlib
matplotlib.use('Agg')
from matplotlib.figure import Figure
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg

class ScrollableFrame(ttk.Frame):
    def __init__(self, container, *args, **kwargs):
        super().__init__(container, *args, **kwargs)
        
        # Configure grid weights
        self.grid_columnconfigure(0, weight=1)
        self.grid_rowconfigure(0, weight=1)

        # Create scrollable canvas
        self.canvas = tk.Canvas(self, highlightthickness=0, background=self.winfo_toplevel().cget('bg'))
        scrollbar = ttk.Scrollbar(self, orient="vertical", command=self.canvas.yview)
        self.scrollable_frame = ttk.Frame(self.canvas)
        
        # Configure scrollable frame
        self.scrollable_frame.grid_columnconfigure(0, weight=1)
        
        # Create window inside canvas
        self.window_id = self.canvas.create_window((0, 0), window=self.scrollable_frame, anchor="nw")

        # Configure scrolling and resizing
        def configure_scroll_region(event):
            self.canvas.configure(scrollregion=self.canvas.bbox("all"))
        
        def configure_window_size(event):
            self.canvas.itemconfig(self.window_id, width=event.width)
        
        self.scrollable_frame.bind("<Configure>", configure_scroll_region)
        self.canvas.bind("<Configure>", configure_window_size)

        # Place canvas and scrollbar in grid
        self.canvas.grid(row=0, column=0, sticky="nsew")
        scrollbar.grid(row=0, column=1, sticky="ns")

        # Configure canvas
        self.canvas.configure(yscrollcommand=scrollbar.set)


def create_algorithm_section(parent, title):
    frame = ttk.Frame(parent, padding=10, relief="groove")
    frame.rowconfigure(0, weight=0)
    frame.rowconfigure(1, weight=1)
    frame.columnconfigure(0, weight=1)

    ttk.Label(frame, text=title, font=("Segoe UI", 12, "bold")).grid(row=0, column=0, sticky="ew", pady=(0, 5))

    table_frame = ttk.Frame(frame, relief="ridge")
    table_frame.grid(row=1, column=0, sticky="nsew", pady=(0, 5))

    return frame, table_frame


def create_bottom_sections(parent):
    container = ttk.Frame(parent)
    container.grid(row=1, column=0, sticky="nsew", padx=10, pady=10)

    fifo_section, fifo_table = create_algorithm_section(container, "FIFO Page Replacement")
    lru_section, lru_table = create_algorithm_section(container, "LRU Page Replacement")
    opt_section, opt_table = create_algorithm_section(container, "Optimal Page Replacement")

    fifo_section.grid(row=0, column=0, sticky="nsew", padx=5)
    lru_section.grid(row=0, column=1, sticky="nsew", padx=5)
    opt_section.grid(row=0, column=2, sticky="nsew", padx=5)

    for i in range(3):
        container.columnconfigure(i, weight=1)
    container.rowconfigure(0, weight=1)

    # Add a single graph area below the tables
    graph_area = ttk.Frame(parent)
    graph_area.grid(row=2, column=0, sticky="nsew", padx=10, pady=(0,10))
    parent.grid_rowconfigure(2, weight=1)

    return {
        'FIFO': fifo_table,
        'LRU': lru_table,
        'OPT': opt_table,
        'GRAPH': graph_area
    }


def generate_references(entry_ref, entry_pages, container):
    # Clear existing boxes
    for widget in container.winfo_children():
        widget.destroy()

    try:
        num_refs = int(entry_ref.get())
        num_pages = int(entry_pages.get())
    except ValueError:
        return

    values = np.random.randint(1, num_pages + 1, size=num_refs)

    # Create boxes frame
    boxes_frame = ttk.Frame(container)
    boxes_frame.grid(row=0, column=0, sticky="nsew")
    
    # Force container to calculate its width
    container.update_idletasks()
    width = container.winfo_width()
    
    # Calculate number of columns
    box_width = 40  # Width in pixels (Entry + padding)
    num_columns = max(1, (width - 20) // box_width)  # -20 for frame padding
    
    # Create and position boxes
    global GLOBAL_REF_BOXES
    GLOBAL_REF_BOXES = []
    for i, val in enumerate(values):
        row, col = divmod(i, num_columns)
        box = ttk.Entry(boxes_frame, width=4, justify="center")
        box.insert(0, str(val))
        box.grid(row=row, column=col, padx=2, pady=2, sticky="ew")
        GLOBAL_REF_BOXES.append(box)
    # Make all columns equal width
    for i in range(num_columns):
        boxes_frame.grid_columnconfigure(i, weight=1)
    # Update layout
    boxes_frame.update_idletasks()


def create_input_section(parent):
    # Main input section frame
    frame = ttk.Frame(parent, relief="groove")
    frame.grid(row=0, column=0, sticky="nsew", padx=10, pady=10)
    
    # Configure frame to expand properly
    frame.grid_columnconfigure(0, weight=1)
    frame.grid_rowconfigure(1, weight=1)

    # Controls row frame
    input_row = ttk.Frame(frame)
    input_row.grid(row=0, column=0, sticky="ew", padx=5, pady=5)
    
    # Add controls
    controls = [
        ("Number of References:", entry_ref := ttk.Entry(input_row, width=10)),
        ("Number of Pages:", entry_pages := ttk.Entry(input_row, width=10)),
        ("Number of Frames:", entry_frames := ttk.Entry(input_row, width=10))
    ]
    
    for col, (label_text, entry) in enumerate(controls):
        ttk.Label(input_row, text=label_text).grid(row=0, column=col*2, padx=5)
        entry.grid(row=0, column=col*2+1, padx=5)
        entry.insert(0, "25" if col == 1 else "300" if col == 0 else "15")
    
    btn_generate = ttk.Button(input_row, text="Generate")
    btn_generate.grid(row=0, column=len(controls)*2, padx=5)
    btn_submit = ttk.Button(input_row, text="Submit")
    btn_submit.grid(row=0, column=len(controls)*2+1, padx=5)

    # References area with scroll
    refs_container = ttk.Frame(frame)
    refs_container.grid(row=1, column=0, sticky="nsew", pady=(8, 4), padx=(5, 5))  # Adjusted margins
    refs_container.grid_columnconfigure(0, weight=1)
    refs_container.grid_rowconfigure(0, weight=1)

    # Create a container with fixed height
    fixed_height_container = ttk.Frame(refs_container, height=35)  # Reduced height to match 10% proportion
    fixed_height_container.grid(row=0, column=0, sticky="nsew")
    fixed_height_container.grid_propagate(False)  # Prevent height from expanding
    fixed_height_container.grid_columnconfigure(0, weight=1)
    fixed_height_container.grid_rowconfigure(0, weight=1)

    scrollable_refs = ScrollableFrame(fixed_height_container)
    scrollable_refs.grid(row=0, column=0, sticky="nsew")

    btn_generate.configure(command=lambda: generate_references(entry_ref, entry_pages, scrollable_refs.scrollable_frame))

    # Store reference to entry boxes for later use
    frame.entry_ref = entry_ref
    frame.entry_pages = entry_pages
    frame.entry_frames = entry_frames
    frame.scrollable_refs = scrollable_refs
    def get_reference_values():
        global GLOBAL_REF_BOXES
        num_refs = int(entry_ref.get())
        num_pages = int(entry_pages.get())
        num_frames = int(entry_frames.get())
        refs = [int(box.get()) for box in GLOBAL_REF_BOXES]
        return num_refs, num_pages, num_frames, refs
    frame.get_reference_values = get_reference_values
    frame.btn_submit = btn_submit
    return frame


def main():
    root = tk.Tk()
    root.title("Page Replacement Algorithm Visualizer")
    root.geometry("1200x700")
    
    # Configure root window to split 10-90
    root.grid_rowconfigure(0, minsize=0, weight=1)  # Input section - 10%
    root.grid_rowconfigure(1, minsize=0, weight=9)  # Algorithm section - 90%
    root.grid_columnconfigure(0, weight=1)

    input_section = create_input_section(root)
    table_frames = create_bottom_sections(root)

    def render_table(table_frame, references, frames, page_results):
        # Clear previous table
        for widget in table_frame.winfo_children():
            widget.destroy()
        # Create a canvas for scrolling
        canvas = tk.Canvas(table_frame, height=350, highlightthickness=0, borderwidth=0)
        canvas.grid(row=0, column=0, sticky="nsew")
        table_frame.grid_rowconfigure(0, weight=1)
        table_frame.grid_columnconfigure(0, weight=1)

        # Add a single vertical scrollbar for the canvas
        scrollbar = ttk.Scrollbar(table_frame, orient="vertical", command=canvas.yview)
        scrollbar.grid(row=0, column=1, sticky="ns")
        canvas.configure(yscrollcommand=scrollbar.set)

        # Create scrollable frame inside canvas
        scrollable_frame = ttk.Frame(canvas)
        window_id = canvas.create_window((0, 0), window=scrollable_frame, anchor="nw")

        def on_frame_configure(event):
            canvas.configure(scrollregion=canvas.bbox("all"))
            canvas.itemconfig(window_id, width=canvas.winfo_width())
        scrollable_frame.bind("<Configure>", on_frame_configure)
        canvas.bind("<Configure>", lambda e: canvas.itemconfig(window_id, width=e.width))

        # Table header
        ttk.Label(scrollable_frame, text="Reference", anchor="center", font=("Segoe UI", 10, "bold"), background="#e0e0e0", padding=(4,2)).grid(row=0, column=0, sticky="ew", padx=2, pady=1)
        ttk.Label(scrollable_frame, text="Frames", anchor="center", font=("Segoe UI", 10, "bold"), background="#e0e0e0", padding=(4,2)).grid(row=0, column=1, sticky="ew", padx=2, pady=1)
        ttk.Label(scrollable_frame, text="Page", anchor="center", font=("Segoe UI", 10, "bold"), background="#e0e0e0", padding=(4,2)).grid(row=0, column=2, sticky="ew", padx=2, pady=1)
        scrollable_frame.grid_columnconfigure(0, weight=1)
        scrollable_frame.grid_columnconfigure(1, weight=7)
        scrollable_frame.grid_columnconfigure(2, weight=2)

        # Table rows
        for i, (ref, frame_row, page_result) in enumerate(zip(references, frames, page_results)):
            color = "#b6fcb6" if page_result == "Hit" else None
            # Reference
            ttk.Label(scrollable_frame, text=str(ref), anchor="center", background=color, padding=(4,2)).grid(row=i+1, column=0, sticky="ew", padx=2, pady=1)
            # Frames (fixed width for each number)
            def format_frame(f):
                if f is None:
                    return "   "  # 3 spaces for missing
                return f"{str(f):>3}"
            frames_str = " ".join(format_frame(f) for f in frame_row)
            ttk.Label(scrollable_frame, text=frames_str, anchor="center", background=color, font=("Consolas", 10), padding=(4,2)).grid(row=i+1, column=1, sticky="ew", padx=2, pady=1)
            # Page (hit/fault)
            ttk.Label(scrollable_frame, text=page_result, anchor="center", background=color, padding=(4,2)).grid(row=i+1, column=2, sticky="ew", padx=2, pady=1)

    def fifo_algorithm(refs, num_frames):
        frames = [None] * num_frames
        frame_states = []
        page_results = []
        queue = []
        for ref in refs:
            if ref in frames:
                page_results.append("Hit")
            else:
                page_results.append("Fault")
                if None in frames:
                    idx = frames.index(None)
                    frames[idx] = ref
                    queue.append(idx)
                else:
                    idx = queue.pop(0)
                    frames[idx] = ref
                    queue.append(idx)
            frame_states.append(frames.copy())
        return frame_states, page_results

    def lru_algorithm(refs, num_frames):
        frames = []
        frame_states = []
        page_results = []
        for i, ref in enumerate(refs):
            if ref in frames:
                page_results.append("Hit")
                frames.remove(ref)
                frames.append(ref)
            else:
                page_results.append("Fault")
                if len(frames) < num_frames:
                    frames.append(ref)
                else:
                    frames.pop(0)
                    frames.append(ref)
            # Pad frames to num_frames
            frame_states.append(frames + [None]*(num_frames-len(frames)))
        return frame_states, page_results

    def optimal_algorithm(refs, num_frames):
        frames = []
        frame_states = []
        page_results = []
        for i, ref in enumerate(refs):
            if ref in frames:
                page_results.append("Hit")
            else:
                page_results.append("Fault")
                if len(frames) < num_frames:
                    frames.append(ref)
                else:
                    # Find the frame to replace
                    future = refs[i+1:]
                    indices = [future.index(f) if f in future else float('inf') for f in frames]
                    idx = indices.index(max(indices))
                    frames[idx] = ref
            frame_states.append(frames + [None]*(num_frames-len(frames)))
        return frame_states, page_results

    def on_submit():
      num_refs, num_pages, num_frames, refs = input_section.get_reference_values()
      # FIFO
      fifo_frames, fifo_results = fifo_algorithm(refs, num_frames)
      render_table(table_frames['FIFO'], refs, fifo_frames, fifo_results)
      # LRU
      lru_frames, lru_results = lru_algorithm(refs, num_frames)
      render_table(table_frames['LRU'], refs, lru_frames, lru_results)
      # OPTIMAL
      opt_frames, opt_results = optimal_algorithm(refs, num_frames)
      render_table(table_frames['OPT'], refs, opt_frames, opt_results)

      # Calculate hits and faults for each algorithm
      def count_hits_faults(results):
          hits = sum(1 for r in results if r == "Hit")
          faults = sum(1 for r in results if r == "Fault")
          return hits, faults
      fifo_hits, fifo_faults = count_hits_faults(fifo_results)
      lru_hits, lru_faults = count_hits_faults(lru_results)
      opt_hits, opt_faults = count_hits_faults(opt_results)

      # Draw stacked horizontal bar chart
      graph_frame = table_frames['GRAPH']
      for widget in graph_frame.winfo_children():
          widget.destroy()

      fig = Figure(figsize=(8, 2.5), dpi=100)
      ax = fig.add_subplot(111)
      algorithms = ["FIFO", "LRU", "Optimal"]
      hits = [fifo_hits, lru_hits, opt_hits]
      faults = [fifo_faults, lru_faults, opt_faults]
      import numpy as np
      y_pos = np.arange(len(algorithms))

      ax.barh(y_pos, hits, color='green', label='Page Hits')
      ax.barh(y_pos, faults, left=hits, color='red', label='Page Faults')
      ax.set_yticks(y_pos)
      ax.set_yticklabels(algorithms)
      ax.set_xlabel('Count')
      ax.set_title('Page Hits vs Faults (Stacked)')
      ax.legend(loc='upper right')
      ax.set_xlim(0, max(hits[i]+faults[i] for i in range(3)) * 1.1)
      fig.tight_layout()

      canvas = FigureCanvasTkAgg(fig, master=graph_frame)
      canvas.draw()
      canvas.get_tk_widget().pack(fill='both', expand=True)

    input_section.btn_submit.configure(command=on_submit)

    root.mainloop()


if __name__ == "__main__":
    main()
